/*
** EPITECH PROJECT, 2021
** printf
** File description:
** 8 novembre
*/

#include <stdarg.h>
#include <unistd.h>

#include "my.h"

const printf_flag_t flags[10] = {
    { 's', &print_string },
    { 'S', &print_spec_string },
    { 'd', &print_integer },
    { 'i', &print_integer },
    { 'b', &print_binary },
    { 'x', &print_hexadecimal_low },
    { 'X', &print_hexadecimal },
    { 'o', &print_unsigned_octal },
    { 'u', &print_unsigned_dec },
    { 'p', &print_ptr },
};

void check_printf_percent(va_list list, int *i, char pc, char c)
{
    for (int index = 0; index < 10; ++index) {
        if (c == flags[index].flag) {
            flags[index].ptr_function(list);
            ++(*i);
            return;
        }
    }
    if (c == 'c') {
        my_putchar(va_arg(list, int));
        ++(*i);
        return;
    }
    if (c == '%') {
        my_putchar(c);
        ++(*i);
        return;
    }
    my_putchar(pc);
}

void my_printf(char *str, ...)
{
    va_list list;
    char *base_string = str;

    va_start(list, str);
    for (int i = 0; base_string[i] != '\0'; ++i) {
        if (base_string[i] == '%') {
            check_printf_percent(list, &i, base_string[i], base_string[i + 1]);
        } else {
            my_putchar(base_string[i]);
        }
    }
    va_end(list);
}

void mprintf(char *str, ...)
{
    va_list list;
    char *base_string = str;

    va_start(list, str);
    for (int i = 0; base_string[i] != '\0'; ++i) {
        if (base_string[i] == '%') {
            check_printf_percent(list, &i, base_string[i], base_string[i + 1]);
        } else {
            my_putchar(base_string[i]);
        }
    }
    va_end(list);
}
