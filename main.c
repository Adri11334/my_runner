/*
** EPITECH PROJECT, 2021
** Project Generator
** File description:
** Autocreated main File
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

int display_help(void);
int start_program(int argc, char const* const* argv);

int main(int argc, char const* const* argv, char const* const* env)
{
    if (*env == NULL || env == NULL) {
        write_red("[X] Error: env is not set.\n");
        return 84;
    } else
        return start_program(argc, argv);
}
