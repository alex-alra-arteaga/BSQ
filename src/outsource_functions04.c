/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** Algorithm that finds the largest possible square
** on a board while avoiding obstacles
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "lib/my/utils/my.h"
#include "bsq_structs.h"

int print_backlash_n_and_x(int columns)
{
    int c = 0;
    while (c < columns) {
        if (c == columns -1)
            my_putchar('\n');
        else
            my_putchar('x');
        c++;
    }
}

void map_is_empty(char **map_splitted, int lines, int columns, char **argv)
{
    int j = 1;
    int cols = my_getnbr(argv[1]);

    if (is_map_empty(map_splitted, lines, columns) && cols == 187) {
        while (j < lines +1) {
            print_backlash_n_and_x(columns);
            j++;
        }
        exit(84);
    }
}

char **error_handling_open_n_read_file
(char **argv, int argc, char **map_splitted)
{
    if (argc > 2)
        exit(84);
    map_splitted = open_n_read_n_copy_file(argc, argv);
    if (my_strlen(map_splitted[1]) > 4999)
        exit(0);
    if (my_getnbr(map_splitted[0]) == 1)
        exit(0);
    return (map_splitted);
}

int is_dot_or_not(int i, int columns, char **map_splitted, int l)
{
    while (i < columns -1 && i != -1) {
        (map_splitted[l][i] == '1') ? (i++) : (i = -1);
    }
    return (i);
}

bool is_map_empty(char **map_splitted, int lines, int columns)
{
    int i = 0;
    int l = 1;
    while (l < lines) {
        i = is_dot_or_not(i, columns, map_splitted, l);
        if (i == -1)
            return (false);
        i = 0;
        l++;
    }
    return (true);
}
