/*
** EPITECH PROJECT, 2022
** key.c
** File description:
** key
*/

#include "../include/my_sokoban.h"

int key_pressed(int key, struct map *mp)
{
    int pos = 0; int n = 0; pos = pos_function(key, mp);
    if (pos == 1) {
        if (key == KEY_UP) {
            up_fun(mp);
        }
        if (key == KEY_DOWN) {
            down(mp);
        }
        if (key == KEY_LEFT) {
            left(mp);
        }
        key_dch(key, mp);
        if (key == ' ') {
            n = 2;
        }
        if (mp->numdeoconx == mp->num_x) {
            n = 1;
        }
    }
    return n;
}

int key_up(int key, struct map *mp)
{
    int pos = 0;
    if (key == KEY_UP) {
        if (mp->map[mp->pos_i - 1][mp->pos_j] != '#') {
            pos = 1;
        }
        if (pos == 1 && comprobar_ox(mp, mp->pos_i - 1, mp->pos_j) == 1) {
            pos = 0;
        }
    }
    return pos;
}

int key_down(int key, struct map *mp)
{
    int pos = 0;
    if (key == KEY_DOWN) {
        if (mp->map[mp->pos_i + 1][mp->pos_j] != '#') {
            pos = 1;
        }
        if (pos == 1 && comprobar_ox(mp, mp->pos_i + 1, mp->pos_j) == 1) {
            pos = 0;
        }
    }
    return pos;
}

int key_left(int key, struct map *mp)
{
    int pos = 0;
    if (key == KEY_LEFT) {
        if (mp->map[mp->pos_i][mp->pos_j - 1] != '#') {
            pos = 1;
        }
        if (pos == 1 && comprobar_ox(mp, mp->pos_i, mp->pos_j - 1) == 1) {
            pos = 0;
        }
    }
    return pos;
}

int key_right(int key, struct map *mp)
{
    int pos = 0;
    if (key == KEY_RIGHT) {
        if (mp->map[mp->pos_i][mp->pos_j + 1] != '#') {
            pos = 1;
        }
        if (pos == 1 && comprobar_ox(mp, mp->pos_i, mp->pos_j + 1) == 1) {
            pos = 0;
        }
    }
    return pos;
}
