/*
** EPITECH PROJECT, 2021
** my lib
** File description:
** print of a certain color pt 2
*/

void my_printf(char *str, ...);

void write_purple(char *str)
{
    my_printf("\x1B[35m%s\x1B[0m", str);
}
