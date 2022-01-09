/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu
*/

#include "my_runner.h"

void shrek_menu_anim(entity_t *entity)
{
    sfTime time;
    float milli_seconds;
    gameobject *obj = entity->player;

    time = sfClock_getElapsedTime(obj->clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > obj->clock_rate * 2) {
        if (obj->rect.left + 43 < 172)
            obj->rect.left += 43;
        else if (obj->rect.left + 38 < 240)
            obj->rect.left += 38;
        else
            obj->rect.left = 0;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfClock_restart(obj->clock);
    }
    display_object(obj, entity->window);
}
