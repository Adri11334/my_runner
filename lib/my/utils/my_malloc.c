/*
** EPITECH PROJECT, 2021
** my malloc
** File description:
** malloc gestion
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

void *my_malloc(int size, char *buf)
{
    char *str = malloc(size);
    int buf_len = -1;

    if (buf != NULL)
        buf_len = my_strlen(buf);
    for (int i = 0; i < size; i++) {
        if (i < buf_len)
            str[i] = buf[i];
        else
            str[i] = 0;
    }
    return str;
}
