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

int **change_values
(int** int_map_splitted, int columns, int l, char **map_splitted)
{
    int c = 0;
    while (c < columns) {
        if (c != columns -1) {
            int_map_splitted[l][c] = map_splitted[l + 1][c] - 48;
        }
        c++;
    }
    return (int_map_splitted);
}

int **pass_char_to_int
(int lines, int columns, int **int_map_splitted, char **map_splitted)
{
    int l = 0;
    int c = 0;

    while (l < lines) {
        int_map_splitted = change_values
                (int_map_splitted, columns, l, map_splitted);
        l++;
    }
    return (int_map_splitted);
}

int **check_for_conditions_n_compute_algorithm
(int **int_map_splitted, int c, int l, int columns)
{
    int *nearby_int;
    int i;

    if (int_map_splitted[l][c -1] != 0
        && int_map_splitted[l -1][c -1] != 0
        && int_map_splitted[l -1][c] != 0
        && int_map_splitted[l][c] != 0
        && c != columns -1) {
        nearby_int = malloc(sizeof(int) *4);
        for (i = 0; i < 4; i++)
            nearby_int[i] = 0;
        nearby_int[0] = int_map_splitted[l][c - 1];
        nearby_int[1] = int_map_splitted[l - 1][c -1];
        nearby_int[2] = int_map_splitted[l - 1][c];
        my_sort_int_array(nearby_int, 3);
        int_map_splitted[l][c] += nearby_int[0];
        free(nearby_int);
    }
    return (int_map_splitted);
}

int **bsq_algorithm(int lines, int columns, int **int_map_splitted)
{
    int l = 1;
    int c = 1;

    while (l +1 < lines) {
        while (c < columns) {
            int_map_splitted = check_for_conditions_n_compute_algorithm
                    (int_map_splitted, c, l, columns);
            c++;
        }
        c = 1;
        l++;
    }
    return (int_map_splitted);
}

int detect_higher_num(int **int_map_splitted, int l, int c, int higher_num)
{
    if (int_map_splitted[l][c] > higher_num && int_map_splitted[l][c] != '\n')
        higher_num = int_map_splitted[l][c];
    return (higher_num);
}
