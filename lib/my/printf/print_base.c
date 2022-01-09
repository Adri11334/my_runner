/*
** EPITECH PROJECT, 2021
** printf
** File description:
** bases print functions
*/

#include <stdarg.h>
#include <stdlib.h>

int to_octal(int dec);
void my_putchar(char c);
int my_put_nbr(int nb);
void print_octal(int nb);
void to_binary(unsigned int dec, char *binary, int len);
void to_hex(unsigned int dec, char *hex, int len);
char *my_strlowcase(char *str);

void print_octal(int nb)
{
    int octal = to_octal(nb);

    my_putchar('\\');
    for (int i = 1; octal * i < 100; i *= 10) {
        my_putchar('0');
    }
    my_put_nbr(octal);
}

void print_spec_string(va_list arg)
{
    char *str = va_arg(arg, char*);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < 32) {
            print_octal((int)str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}

void print_binary(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *binary = malloc(33);
    int start_print = 0;

    to_binary(nb, binary, 33);
    while (binary[start_print] != '1') {
        start_print++;
    }
    for (int i = start_print; binary[i] != '\0'; ++i)
        my_putchar(binary[i]);
    free(binary);
}

void print_hexadecimal(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *hexa = malloc(33);
    int start_print = 0;

    to_hex(nb, hexa, 33);
    while (hexa[start_print] > 70)
        (start_print)++;
    for (int i = start_print; hexa[i] != '\0'; ++i)
        my_putchar(hexa[i]);
    free(hexa);
}

void print_hexadecimal_low(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *hexa = malloc(33);
    int start_print = 0;

    to_hex(nb, hexa, 33);
    hexa = my_strlowcase(hexa);
    while (hexa[start_print] > 102)
        (start_print)++;
    for (int i = start_print; hexa[i] != '\0'; ++i)
        my_putchar(hexa[i]);
    free(hexa);
}
