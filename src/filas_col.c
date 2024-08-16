/*
** EPITECH PROJECT, 2022
** filascol.c
** File description:
** filascol
*/

#include "../include/my_sokoban.h"
int num_filas(char *buffer)
{
    int nfilas = 0; int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            nfilas++;
        }
        i++;
    }
    return (nfilas + 1);
}

int num_col(char *buffer, struct map *m)
{
    int i = 0; int n = 0; int j = 0; int ant = 0;
    m->col = (int*) malloc(sizeof(int) * m->filas);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            m->col[n] = j; n++; j = 0;
        } else {
            j++;
        }
        i++;
    }
    if (buffer[i] == '\0') {
        m->col[n] = j;
    }
    return i;
}
