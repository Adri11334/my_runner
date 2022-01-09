/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game
*/

#include "my_runner.h"
#include <stdlib.h>

float gen_random_float(float min, float max)
{
    srand((unsigned int)time(NULL));

    float number = ((float)rand() / (float)(RAND_MAX)) * max;
    while (number < min)
        number = ((float)rand() / (float)(RAND_MAX)) * max;
    return number;
}

void scene(entity_t *entity)
{
    if (entity->window->stat == MENU)
        in_menu_manager(entity);
    if (entity->window->stat == PLAYING)
        in_game_manager(entity);
    if (entity->window->stat == VICTORY)
        in_victory_manager(entity);
}
