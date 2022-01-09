/*
** EPITECH PROJECT, 2021
** my lib
** File description:
** print of a certain color
*/

void my_printf(char *str, ...);

void write_white(char *str)
{
    my_printf("\x1B[37m%s\x1B[0m", str);
}

void write_blue(char *str)
{
    my_printf("\x1B[34m%s\x1B[0m", str);
}

void write_green(char *str)
{
    my_printf("\x1B[32m%s\x1B[0m", str);
}

void write_cyan(char *str)
{
    my_printf("\x1B[36m%s\x1B[0m", str);
}

void write_red(char *str)
{
    my_printf("\x1B[31m%s\x1B[0m", str);
}
