/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_to_string
*/

#include "my.h"
#include <stdlib.h>

char *my_to_str(int nb)
{
    int range = 1;
    int nb_buff = nb;
    char *str = my_malloc(12, NULL);
    int index = 0;

    while (nb_buff > 9) {
        nb_buff /= 10;
        range *= 10;
    }
    while (range >= 1) {
        str[index] = ((nb / range) % 10) + '0';
        range /= 10;
        index++;
    }
    return (str);
}
