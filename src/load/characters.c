/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** players
*/

#include "my_runner.h"

int load_shrek(entity_t *entity)
{
    sfVector2f shrek_pos = {200, 670};
    sfIntRect texture_rect = {6, 16, 362, 644};
    sfIntRect shrek_rect = {0, 46, 33, 40};
    sfVector2f scale = { .x = 5, .y = 5 };

    my_printf("Loading game player...\n");
    entity->player = create_object("assets/img/shrek.png", shrek_pos,
    texture_rect, SHREK);
    if (!entity->player)
        return 84;
    sfSprite_setScale(entity->player->sprite, scale);
    entity->player->rect = shrek_rect;
    sfSprite_setTextureRect(entity->player->sprite, entity->player->rect);
    entity->player->clock_rate = 32;
    entity->player->speed = 34;
    return 0;
}

int load_lord_f(entity_t *entity)
{
    sfVector2f lord_pos = {1951, 755};
    sfIntRect texture_rect = {7, 7, 305, 348};
    sfIntRect lord_rect = {0, 0, 31, 40};
    sfVector2f scale = { .x = -3, .y = 3 };
    gameobject *obj = create_object("assets/img/lord_f.png", lord_pos,
    texture_rect, LORD_F);

    if (!entity->player)
        return 84;
    write_purple("[v] Lord Farquad loaded\n");
    sfSprite_setScale(obj->sprite, scale);
    obj->rect = lord_rect;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->clock_rate = 50;
    obj->speed = 31;
    push_node(&entity->enemies, obj);
    return 0;
}

int load_guard(entity_t *entity)
{
    sfVector2f guard_pos = {1985, 740};
    sfIntRect texture_rect = {7, 7, 336, 308};
    sfIntRect guard_rect = {0, 126, 65, 50};
    sfVector2f scale = { .x = -3.1, .y = 3.1 };
    gameobject *obj = create_object("assets/img/guard.png", guard_pos,
    texture_rect, GUARD);

    if (!entity->player)
        return 84;
    write_purple("[V] Guard loaded\n");
    sfSprite_setScale(obj->sprite, scale);
    obj->rect = guard_rect;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->clock_rate = 50;
    obj->speed = 65;
    push_node(&entity->enemies, obj);
    return 0;
}
