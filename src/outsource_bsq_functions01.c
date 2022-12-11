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
#include <stdbool.h>

int error_handling_n_open_bsq(int argc, char **argv, int fd)
{
    if (argc != 2) {
        my_putstr_stderr("Incorrect number of arguments\n");
        exit(84);
    }
    if (argv[1][0] == '.' || argv[1][0] == 'o')
        exit(84);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        my_putstr_stderr("\"ls: cannot open file '");
        my_putstr_stderr(argv[1]);
        my_putstr_stderr(": Permission denied\n");
        exit(84);
    }
    return (fd);
}

void initialize_n_put_backlash_ns
(int c, int l, int columns, int **int_map_splitted)
{
    if (c == columns -1) {
        int_map_splitted[l][c] = '\n';
    } else {
        int_map_splitted[l][c] = 0;
    }
}

int **malloc_int_array_array(int lines, int columns)
{
    int **int_map_splitted;
    int l = 0;
    int c = 0;

    int_map_splitted = malloc(sizeof(int*) * lines +8);
    int_map_splitted[0] = 0;
    while (l < lines) {
        int_map_splitted[l] = malloc(sizeof(int) * columns + sizeof(int));
        while (c < columns) {
            initialize_n_put_backlash_ns(c, l, columns, int_map_splitted);
            c++;
        }
        c = 0;
        l++;
    }
    return (int_map_splitted);
}

char *convert_to_num(int offset, int len, char *buff)
{
    int i = 0;
    if (len < 0) {
        my_putstr_stderr("Cannot read\n");
        exit(84);
    }
    while (i != offset) {
        if (buff[i] == 'o')
            buff[i] = '0';
        if (buff[i] == '.')
            buff[i] = '1';
        i++;
    }
    return (buff);
}

char **open_n_read_n_copy_file(int argc, char **argv)
{
    struct stat sb;
    int len;
    int fd;
    int offset = 0;
    char **map_splitted;
    char *buff;
    fd = error_handling_n_open_bsq(argc, argv, fd);
    stat(argv[1], &sb);
    buff = malloc(sizeof(char) * sb.st_size + 1);
    buff[0] = '\0';
    while ((len = read(fd, buff +offset, sb.st_size -offset)) > 0)
        offset = offset + len;
    crash_handling(buff);
    buff[offset] = '\0';
    buff = convert_to_num(offset, len, buff);
    map_splitted = my_split(buff, '\n');
    free(buff);
    return (map_splitted);
}
