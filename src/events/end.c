/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** end
*/

#include "my_runner.h"

void map_ended(entity_t *entity)
{
    if (entity->map->map_ended || node_length(entity->enemies) <= 1) {
        entity->window->stat = VICTORY;
        scene(entity);
    }
}
