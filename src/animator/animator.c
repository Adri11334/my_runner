/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** animator
*/

#include "my_runner.h"

void charactere_detection(gameobject *obj, entity_t *entity)
{
    if (obj->type == SHREK) {
        if (entity->user->is_jumping)
            jump_anim(entity->player, entity->user);
        else
            shrek_run(entity->player);
    }
    if (obj->type == LORD_F)
        lord_farquad_run(obj);
    if (obj->type == GUARD)
        guard_run(obj);
}

void clocker(entity_t *entity)
{
    sfTime time;
    float milli_seconds;
    gameobject *obj = entity->player;

    time = sfClock_getElapsedTime(obj->clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > obj->clock_rate) {
        charactere_detection(obj, entity);
        sfClock_restart(obj->clock);
    }
    display_enemys(entity);
    display_object(obj, entity->window);
}
