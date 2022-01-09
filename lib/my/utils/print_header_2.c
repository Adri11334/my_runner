/*
** EPITECH PROJECT, 2021
** my_lib
** File description:
** printing header 2
*/

int my_putstr(char const *str);

void purple_header(const char *str)
{
    my_putstr("\n\x1B[35m-------------------------------------------------\n");
    my_putstr("## ");
    my_putstr(str);
    my_putstr("\n-------------------------------------------------\n\x1B[0m");
}
