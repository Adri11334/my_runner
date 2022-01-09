/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** start_game
*/

#include "my_runner.h"

void start_game(entity_t *entity)
{
    sfIntRect shrek_rect = {2, 46, 33, 40};

    entity->window->stat = PLAYING;
    entity->player->rect = shrek_rect;
    sfSprite_setTextureRect(entity->player->sprite, entity->player->rect);
    scene(entity);
}

void restart_game(entity_t *entity)
{
    sfIntRect shrek_rect = {2, 46, 33, 40};

    entity->window->stat = PLAYING;
    entity->player->rect = shrek_rect;
    sfSprite_setTextureRect(entity->player->sprite, entity->player->rect);
    entity->map->map_ended = false;
    entity->map->index = 0;
    if (entity->user->score > entity->user->best_score) {
        entity->user->best_score = entity->user->score;
        write_green("New hight score: ");
        write_green(my_to_str(entity->user->best_score));
        my_putchar('\n');
    }
    entity->user->score = 0;
    scene(entity);
}
