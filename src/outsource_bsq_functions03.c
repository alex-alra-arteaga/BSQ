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

int get_value_of_higher_num(int lines, int columns, int **int_map_splitted)
{
    int l = 0;
    int c = 0;
    int higher_num = 0;

    while (l + 1 < lines) {
        while (c < columns) {
            higher_num = detect_higher_num(int_map_splitted, l, c, higher_num);
            c++;
        }
        c = 1;
        l++;
    }
    return (higher_num);
}

int **iterate_n_change_values
(int **int_map_splitted, int initial_line, int initial_col, int final_col)
{
    while (initial_col <= final_col) {
        int_map_splitted[initial_line -1][initial_col] = -1;
        initial_col++;
    }
    return (int_map_splitted);
}

t_DoubleReturn select_square_area
(int higher_num, int **int_map_splitted, int l, int c)
{
    int initial_line;
    int initial_col;
    t_DoubleReturn s1;
    if (int_map_splitted[l][c] == higher_num) {
        initial_line = l - higher_num +1;
        initial_col = c - higher_num +1;
        while (initial_line++ <= l) {
            int_map_splitted = iterate_n_change_values
                    (int_map_splitted, initial_line, initial_col, c);
            initial_col = c - higher_num +1;
        }
        s1.int_arr_arr = int_map_splitted;
        s1.passes = 1;
    } else {
        s1.passes = 0;
    }
    return (s1);
}

int **find_higher_num_n_select_square_area
(int lines, int columns, int **int_map_splitted, int higher_num)
{
    int l = 0;
    int c = 0;
    int pass = 0;
    t_DoubleReturn s1;

    while (l + 1 < lines && pass == 0) {
        while (c < columns && pass == 0) {
            s1 = select_square_area(higher_num, int_map_splitted, l, c);
            pass = s1.passes;
            c++;
        }
        c = 0;
        l++;
    }
    return (s1.int_arr_arr);
}

char **malloc_array_to_be_printed
(int lines, int columns, char **print_map_splitted)
{
    int cnt = 0;
    print_map_splitted = malloc(sizeof(char*) * lines +8);
    print_map_splitted[0] = 0;
    while (cnt < lines) {
        print_map_splitted[cnt] = malloc(sizeof(char) * columns + sizeof(char));
        cnt++;
    }
    return (print_map_splitted);
}
