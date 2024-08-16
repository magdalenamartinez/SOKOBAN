/*
** EPITECH PROJECT, 2022
** pos_xo.c
** File description:
** posxo
*/

#include "../include/my_sokoban.h"
void ver_pos_xo(struct map *m)
{
    int i = 0; int j = 0;
    while (i < m->filas) {
        j = 0;
        while (j < m->col[i]) {
            function_o(m, i, j);
            function_x(m, i, j);
            j++;
        }
        i++;
    }
}

void function_o(struct map *m, int i, int j)
{
    if (m->map[i][j] == 'O') {
        m->num_o++;
    }
}

void function_x(struct map *m, int i, int j)
{
    if (m->map[i][j] == 'X') {
        m->num_x++;
    }
}
