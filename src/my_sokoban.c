/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "../include/my_sokoban.h"

int my_sokoban_open(char *fpath)
{
    char buffer[MAXBUF] = "NULL"; int len = 0; int offset = 0; int file = 0;
    file = open(fpath, O_RDONLY);
    if (file == -1) {
        return 84;
    }
    while ((len = read(file, buffer + offset, MAXBUF - offset)) > 0) {
        offset += len;
    }
    buffer[offset] = '\0'; close(file); int i = 0; int valid = 0;
    valid = see_ifvalid(buffer); int a = 0;
    if (len >= 0 && valid == 0) {
        a = bucle(buffer); return a;
    } else {
        return 84;
    }
}

int bucle(char *buffer)
{
    int key; int n = 0;
    struct map *mp; mp = malloc(sizeof(struct map));
    mp->filas = num_filas(buffer); num_col(buffer,mp);
    create_map(buffer, mp); initscr(); noecho(); keypad(stdscr, TRUE);
    while (n == 0) {
        print_mapa(mp); key = getch(); n = key_pressed(key, mp);
    }
    endwin(); free(mp);
    return n;
}

int pos_function(int key, struct map *mp)
{
    int posa = 0; int posb = 0; int posc = 0; int posd = 0;
    posa = key_up(key, mp);
    posb = key_down(key, mp);
    posc = key_left(key, mp);
    posd = key_right(key, mp);
    if (posa == 0 && posb == 0 && posc == 0 && posd == 0) {
        return 0;
    } else {
        return 1;
    }
}

void print_mapa(struct map *mp)
{
    for (int i = 0; i < mp->filas; i++) {
        for (int j = 0; j < mp->col[i]; j++) {
            switch_function(mp->map[i][j], i, j);
        }
    }
}

void switch_function(char pos, int i, int j)
{
    int l = 0;
    mvaddch(i, j, pos);
}
