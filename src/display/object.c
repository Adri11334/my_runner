/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** object
*/

#include "my_runner.h"

void display_object(gameobject *obj, window_t *window)
{
    sfRenderWindow_drawSprite(window->window, obj->sprite, NULL);
}
