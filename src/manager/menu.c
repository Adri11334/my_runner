/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** menu manager
*/

#include "my_runner.h"
#include <stdlib.h>

void set_menu_element(entity_t *entity)
{
    sfIntRect shrek_menu_rect = {0, 572, 43, 39};

    set_menu_text(entity);
    entity->player->rect = shrek_menu_rect;
    sfMusic_play(entity->window->main_audio);
    sfSprite_setTextureRect(entity->player->sprite, shrek_menu_rect);
}

void in_menu_manager(entity_t *entity)
{
    sfClock *menu_clock = sfClock_create();
    bool can_start = false;

    set_menu_element(entity);
    while (!can_start) {
        display_menu(entity, menu_clock, &can_start);
        sfRenderWindow_clear(entity->window->window,
        (sfColor){52, 73, 94,1.0});
    }
    while (sfRenderWindow_isOpen(entity->window->window)) {
        while (sfRenderWindow_pollEvent(entity->window->window,
                &entity->window->event))
            analyse_events(entity);
        display_menu_text(entity);
        shrek_menu_anim(entity);
        sfRenderWindow_display(entity->window->window);
        sfRenderWindow_clear(entity->window->window,
        (sfColor){52, 73, 94,1.0});
    }
}
