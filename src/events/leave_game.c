/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** leave_game
*/

#include "my_runner.h"

void leave_game(entity_t *entity)
{
    sfRenderWindow_close(entity->window->window);
}
