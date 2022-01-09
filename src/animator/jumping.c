/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** jumping
*/

#include "my_runner.h"

void shrek_jump(gameobject *obj)
{
    sfIntRect shrek_jumping_rect = {40, 525, 33, 40};

    sfSprite_setTextureRect(obj->sprite, shrek_jumping_rect);
}

void jump_anim(gameobject *obj, user_t *user)
{
    if (user->is_down_jumping)
        user->actual_jump_height -= 14;
    else
        user->actual_jump_height += 19;
    if (user->actual_jump_height > 250) {
        user->is_down_jumping = true;
    }
    if (user->actual_jump_height < 0) {
        user->is_down_jumping = false;
        user->is_jumping = false;
        user->actual_jump_height = 0;
    }
    obj->pos.y = user->base_player_height - user->actual_jump_height;
    sfSprite_setPosition(obj->sprite, obj->pos);
    shrek_jump(obj);
}
