/*
** EPITECH PROJECT, 2021
** bs_myrunner
** File description:
** error_manager
*/

#include "enum.h"
#include "my.h"
#include <stdlib.h>

void error_manager(enum error_type error)
{
    if (error == NOT_REQUIRED_PARAMETER) {
        my_putstr("You didn't provide all the required ");
        my_putstr("parameters in a function.\n");
        return (84);
    }
}
