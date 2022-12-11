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

void exit_filled(char *buff)
{
    int i = 0;
    while (buff[i]) {
        if (buff[i] == 'o' || buff[i] == '\n' || is_num(buff[i]))
            i++;
        else
            return;
    }
    exit(0);
}

void exit_empty(char *buff)
{
    int i = 0;
    while (buff[i]) {
        if (buff[i] == '.' || buff[i] == '\n' || is_num(buff[i]))
            i++;
        else
            return;
    }
    exit(0);
}

void crash_handling(char *buff)
{
    exit_empty(buff);
    exit_filled(buff);
    if (buff == NULL)
        exit(84);
}
