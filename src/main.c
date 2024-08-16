/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my_sokoban.h"

int main(int argc, char **argv)
{
    int a = 0;
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            my_help_sokoban();
        } else {
            a = my_sokoban_open(argv[1]);
        }
        while (a == 2) {
            a = my_sokoban_open(argv[1]);
        }
        return 0;
    } else {
        return (84);
    }
}

void my_help_sokoban(void)
{
    my_printf("This is a game called My Sokoban.\n");
    my_printf("The objective of this game is to move each X into a O.\n");
}
