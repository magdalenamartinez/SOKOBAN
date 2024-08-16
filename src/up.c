/*
** EPITECH PROJECT, 2022
** up.c
** File description:
** up
*/

#include "../include/my_sokoban.h"

int comprobar_ox(struct map *m, int i, int j)
{
    int t = 0; int no_mover = 0;
    while (t < m->numdeoconx) {
        if (m->posdeoconx_x[t] == i && m->posdeoconx_y[t] == j) {
            no_mover = 1; break;
        }
        t++;
    }
    return no_mover;

}

void pos_x_up(struct map *mp)
{
    if (mp->map[mp->pos_i - 1][mp->pos_j] == 'X') {
        if (mp->map[mp->pos_i - 2][mp->pos_j] == '#') {
            mp->no_mover = 1;
        }
        if (mp->map[mp->pos_i - 2][mp->pos_j] == 'X') {
            mp->no_mover = 1;
        }
        if (mp->map[mp->pos_i - 2][mp->pos_j] == ' ') {
            mp->map[mp->pos_i - 2][mp->pos_j] = 'X';
        }
        if (mp->map[mp->pos_i - 2][mp->pos_j] == 'O') {
            mp->map[mp->pos_i - 2][mp->pos_j] = 'X';
            mp->posdeoconx_x[mp->numdeoconx] = mp->pos_i - 2;
            mp->posdeoconx_y[mp->numdeoconx] = mp->pos_j;
            mp->numdeoconx++;
        }
    }
}

void pos_o_up(struct map *mp)
{
    int devolver_cero = 0;
    if (mp->pos_ox == mp->pos_i && mp->pos_oy == mp->pos_j) {
        devolver_cero = 1;
    }
    pos_save_o_up(mp);
    if (mp->no_mover == 0) {
        if (devolver_cero == 1) {
            mp->map[mp->pos_i][mp->pos_j] = 'O';
        } else {
            mp->map[mp->pos_i][mp->pos_j] = ' ';
        }
        mp->map[mp->pos_i - 1][mp->pos_j] = 'P';
        mp->pos_i = mp->pos_i - 1;
    }
    mp->no_mover = 0;
}

void pos_save_o_up(struct map *mp)
{
    if (mp->map[mp->pos_i - 1][mp->pos_j] == 'O') {
        mp->pos_ox = mp->pos_i - 1;
        mp->pos_oy = mp->pos_j;
    }
}

void up_fun(struct map *mp)
{
    pos_x_up(mp); pos_o_up(mp);
}
