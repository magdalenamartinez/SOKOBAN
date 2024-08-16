/*
** EPITECH PROJECT, 2022
** keydch.c
** File description:
** keydch
*/

#include "../include/my_sokoban.h"

void key_dch(int key, struct map *mp)
{
    if (key == KEY_RIGHT) {
        right(mp);
    }
}
