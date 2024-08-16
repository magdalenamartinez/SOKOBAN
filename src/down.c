/*
** EPITECH PROJECT, 2022
** down.c
** File description:
** down
*/

#include "../include/my_sokoban.h"

void pos_x_down(struct map *mp)
{
    if (mp->map[mp->pos_i + 1][mp->pos_j] == 'X') {
        if (mp->map[mp->pos_i + 2][mp->pos_j] == '#') {
            mp->no_mover = 1;
        }
        if (mp->map[mp->pos_i + 2][mp->pos_j] == 'X') {
            mp->no_mover = 1;
        }
        if (mp->map[mp->pos_i + 2][mp->pos_j] == ' ') {
            mp->map[mp->pos_i + 2][mp->pos_j] = 'X';
        }
        if (mp->map[mp->pos_i + 2][mp->pos_j] == 'O') {
            mp->map[mp->pos_i + 2][mp->pos_j] = 'X';
            mp->posdeoconx_x[mp->numdeoconx] = mp->pos_i + 2;
            mp->posdeoconx_y[mp->numdeoconx] = mp->pos_j;
            mp->numdeoconx++;
        }
    }
}

void pos_o_down(struct map *mp)
{
    int devolver_cero = 0;
    if (mp->pos_ox == mp->pos_i && mp->pos_oy == mp->pos_j) {
        devolver_cero = 1;
    }
    pos_save_o_down(mp);
    if (mp->no_mover == 0) {
        if (devolver_cero == 1) {
            mp->map[mp->pos_i][mp->pos_j] = 'O';
        } else {
            mp->map[mp->pos_i][mp->pos_j] = ' ';
        }
        mp->map[mp->pos_i + 1][mp->pos_j] = 'P';
        mp->pos_i = mp->pos_i + 1;
    }
    mp->no_mover = 0;
}

void pos_save_o_down(struct map *mp)
{
    if (mp->map[mp->pos_i + 1][mp->pos_j] == 'O') {
        mp->pos_ox = mp->pos_i + 1;
        mp->pos_oy = mp->pos_j;
    }
}

void down(struct map *mp)
{
    pos_x_down(mp); pos_o_down(mp);
}
