/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** fullscreen
*/

#include "my_runner.h"
#include <SFML/Window/Export.h>
#include <stddef.h>

void switch_fullscreen(entity_t *entity)
{
    sfVideoMode mode = { entity->window->width, entity->window->height, 32 };
    sfRenderWindow *wdw = entity->window->window;

    sfRenderWindow_destroy(wdw);
    if (entity->window->is_fullscreen)
        wdw = sfRenderWindow_create(mode, "SHREK 4", sfClose, NULL);
    else
        wdw = sfRenderWindow_create(mode, "SHREK 4", sfFullscreen, NULL);
    entity->window->is_fullscreen = !entity->window->is_fullscreen;
    sfRenderWindow_setFramerateLimit(wdw, 45);
}
