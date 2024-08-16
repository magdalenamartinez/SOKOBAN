/*
** EPITECH PROJECT, 2022
** create_map.c
** File description:
** create_map
*/

#include "../include/my_sokoban.h"

void create_map(char *buffer, struct map *m)
{
    m->map = (char**) malloc(sizeof(char*) * m->filas);
    m->posdeoconx_x = (int*) malloc(sizeof(int)*m->num_o);
    m->posdeoconx_y = (int*) malloc(sizeof(int)*m->num_o);
    for (int i = 0; i < m->filas; i++) {
        m->map[i] = (char*) malloc(sizeof(char) * (m->col[i] + 1));
    }
    int enc = 0; int i = 0; int j = 0; int n = 0; read_buffer(buffer, m);
    while (i < m->filas && enc == 0) {
        j = 0;
        while (j < m->col[i] && enc == 0) {
            enc = enc_p(m, i, j);
            j++;
        }
        i++;
    }
    m->pos_i = i - 1; m ->pos_j = j - 1; ver_pos_xo(m);
}

int enc_p(struct map *m, int i, int j)
{
    int enc = 0;
    if (m->map[i][j] == 'P') {
        enc = 1;
    }
    return enc;
}

void read_buffer(char *buffer, struct map *m)
{
    int i = 0; int n = 0; int j = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            m->map[n][j] = '\0';
            n++; j = 0;
        } else {
            m->map[n][j] = buffer[i];
            j++;
        }
        i++;
    }
}
