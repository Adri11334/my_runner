/*
** EPITECH PROJECT, 2021
** printf
** File description:
** basics print functions
*/

#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);

void print_string(va_list arg)
{
    char *str = va_arg(arg, char*);

    for (int i = 0; str[i] != '\0'; ++i)
        my_putchar(str[i]);
}

void print_integer(va_list arg)
{
    int nb = va_arg(arg, int);
    my_put_nbr(nb);
}
