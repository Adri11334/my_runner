/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** background
*/

#include "my_runner.h"

void display_layer(gameobject *obj)
{
    sfTime time;
    float milli_seconds;

    time = sfClock_getElapsedTime(obj->clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > obj->clock_rate) {
        parallax_effect(obj);
        sfClock_restart(obj->clock);
    }
}

void display_bkg(entity_t *entity)
{
    background *bkg = entity->bkg;
    window_t *window = entity->window;

    display_layer(bkg->layer2);
    display_layer(bkg->layer3);
    display_layer(bkg->layer5);
    display_object(bkg->layer2, window);
    display_object(bkg->layer3, window);
    display_object(bkg->layer5, window);
}
