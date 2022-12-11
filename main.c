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

char **chech_n_change_values
(int **int_map_splitted, char **print_map_splitted, int l, int c)
{
    if (int_map_splitted[l][c] == 0)
        print_map_splitted[l][c] = 'o';
    if (int_map_splitted[l][c] != -1 && int_map_splitted[l][c] != 0
        && int_map_splitted[l][c] != '\n')
        print_map_splitted[l][c] = '.';
    if (int_map_splitted[l][c] == -1)
        print_map_splitted[l][c] = 'x';
    if (int_map_splitted[l][c] == '\n')
        print_map_splitted[l][c] = '\n';
    return (print_map_splitted);
}

char **replenish_array_to_be_printed
(int lines, int columns, int **int_map_splitted, char **print_map_splitted)
{
    int l = 0;
    int c = 0;
    while (l < lines) {
        while (c < columns) {
            print_map_splitted = chech_n_change_values
                    (int_map_splitted,print_map_splitted, l, c);
            c++;
        }
        c = 0;
        l++;
    }
    return (print_map_splitted);
}

void print_map(int lines, char **print_map_splitted, int columns)
{
    int l = 0;
    while (l < lines) {
        write(1, print_map_splitted[l], columns);
        l++;
    }
}

char **get_map_in_char
(int **int_map_splitted, int lines, int columns, int higher_num)
{
    char **print_map_splitted;
    int_map_splitted = find_higher_num_n_select_square_area
            (lines, columns, int_map_splitted, higher_num);
    print_map_splitted = malloc_array_to_be_printed
            (lines, columns, print_map_splitted);
    print_map_splitted = replenish_array_to_be_printed
            (lines, columns, int_map_splitted, print_map_splitted);
    free(int_map_splitted);
    return (print_map_splitted);
}

int main(int argc, char **argv)
{
    char **map_splitted;
    int **int_map_splitted;
    char **print_map_splitted;
    int higher_num;
    map_splitted = error_handling_open_n_read_file(argv, argc, map_splitted);
    int columns = my_strlen(map_splitted[1]) +1;
    int lines = my_getnbr(map_splitted[0]);
    map_is_empty(map_splitted, lines, columns, argv);
    int_map_splitted = malloc_int_array_array(lines, columns);
    int_map_splitted =
            pass_char_to_int(lines, columns, int_map_splitted, map_splitted);
    free(map_splitted);
    int_map_splitted = bsq_algorithm(lines, columns, int_map_splitted);
    higher_num = get_value_of_higher_num(lines, columns, int_map_splitted);
    print_map_splitted = get_map_in_char
            (int_map_splitted, lines, columns, higher_num);
    print_map(lines, print_map_splitted, columns);
    free(print_map_splitted);
    return (0);
}

// TODO: Mirar si es válido
