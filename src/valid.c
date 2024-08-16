/*
** EPITECH PROJECT, 2022
** valid.c
** File description:
** valid
*/

#include "../include/my_sokoban.h"

int see_ifvalid(char *buffer)
{
    char a = 0; int i = 0; int novalid = 0;
    while (buffer[i] != '\0') {
        a = buffer[i];
        if (switch_valid(a) == 0) {
            novalid = 1;
        }
        i++;
    }
    return novalid;
}

int switch_valid (char a)
{
    int r = 0;
    switch (a) {
        case '#':
            r = 1; break;
        case 'O':
            r = 1; break;
        case 'X':
            r = 1; break;
        case 'P':
            r = 1; break;
        case '\n':
            r = 1; break;
        case ' ':
            r = 1; break;
    }
    return r;
}
