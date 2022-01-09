/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** game manager
*/

#include "my_runner.h"
#include <stdlib.h>

void  in_game_manager(entity_t *entity)
{
    while (sfRenderWindow_isOpen(entity->window->window)) {
        while (sfRenderWindow_pollEvent(entity->window->window,
                &entity->window->event))
            analyse_events(entity);
        display_bkg(entity);
        clocker(entity);
        update_score(entity);
        sfRenderWindow_display(entity->window->window);
        sfRenderWindow_clear(entity->window->window,
        (sfColor){44, 62, 80,1.0});
    }
}
