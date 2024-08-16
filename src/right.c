/*
** EPITECH PROJECT, 2022
** right.c
** File description:
** right
*/

#include "../include/my_sokoban.h"

void pos_x_right(struct map *mp)
{
    if (mp->map[mp->pos_i][mp->pos_j + 1] == 'X') {
        if (mp->map[mp->pos_i][mp->pos_j + 2] == '#') {
            mp->no_mover = 1;
        }
        if (mp->map[mp->pos_i][mp->pos_j + 2] == 'X') {
            mp->no_mover = 1;
        }
        if (mp->map[mp->pos_i][mp->pos_j + 2] == ' ') {
            mp->map[mp->pos_i][mp->pos_j + 2] = 'X';
        }
        if (mp->map[mp->pos_i][mp->pos_j + 2] == 'O') {
            mp->map[mp->pos_i][mp->pos_j + 2] = 'X';
            mp->posdeoconx_x[mp->numdeoconx] = mp->pos_i;
            mp->posdeoconx_y[mp->numdeoconx] = mp->pos_j + 2;
            mp->numdeoconx++;
        }
    }
}

void pos_o_right(struct map *mp)
{
    int devolver_cero = 0;
    if (mp->pos_ox == mp->pos_i && mp->pos_oy == mp->pos_j) {
        devolver_cero = 1;
    }
    pos_save_o_right(mp);
    if (mp->no_mover == 0) {
        if (devolver_cero == 1) {
            mp->map[mp->pos_i][mp->pos_j] = 'O';
        } else {
            mp->map[mp->pos_i][mp->pos_j] = ' ';
        }
        mp->map[mp->pos_i][mp->pos_j + 1] = 'P';
        mp->pos_j = mp->pos_j + 1;
    }
    mp->no_mover = 0;
}

void pos_save_o_right(struct map *mp)
{
    if (mp->map[mp->pos_i][mp->pos_j + 1] == 'O') {
        mp->pos_ox = mp->pos_i;
        mp->pos_oy = mp->pos_j + 1;
    }
}

void right(struct map *mp)
{
    pos_x_right(mp);
    pos_o_right(mp);
}
