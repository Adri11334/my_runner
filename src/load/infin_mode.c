/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** infin_mode
*/

#include <fcntl.h>

#include "my_runner.h"

infinmode_t *load_infinite_mode_settings(entity_t *entity)
{
    infinmode_t *infinmode = malloc(sizeof(infinmode_t));

    if (entity->infinite_mode == false)
        return NULL;
    infinmode->score_clock = sfClock_create();
    infinmode->spawn_clock = sfClock_create();
    infinmode->spawn_rate = 1;
    return infinmode;
}

void destroy_infinite_mode(entity_t *entity)
{
    infinmode_t *infinmode = entity->infinite_mode_settings;

    if (entity->infinite_mode) {
        sfClock_destroy(infinmode->score_clock);
        sfClock_destroy(infinmode->spawn_clock);
        free(infinmode);
    }
}
