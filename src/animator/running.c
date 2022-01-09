/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** running
*/

#include "my_runner.h"

void shrek_run(gameobject *obj)
{
    if (obj->rect.left + obj->speed < 195)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void lord_farquad_run(gameobject *obj)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f new_pos = { .x = pos.x, .y = pos.y };

    new_pos.x = pos.x - 18;
    if (obj->rect.top != 93)
        obj->rect.top = 93;
    if (obj->rect.left + obj->speed < 93)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    obj->pos = new_pos;
    sfSprite_setPosition(obj->sprite, new_pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void guard_run(gameobject *obj)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f new_pos = { .x = pos.x, .y = pos.y };

    new_pos.x = pos.x - 22;
    if (obj->rect.left + obj->speed < 195)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    obj->pos = new_pos;
    sfSprite_setPosition(obj->sprite, new_pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}
