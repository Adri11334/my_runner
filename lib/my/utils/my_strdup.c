/*
** EPITECH PROJECT, 2021
** my str duplicate
** File description:
** task 01
*/

# include <stdlib.h>
# include <stdio.h>

int my_strlen (char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *new_str;

    new_str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        new_str[i] = src[i];
        i++;
    }
    new_str[i + 1] = '\0';
    return (new_str);
}
