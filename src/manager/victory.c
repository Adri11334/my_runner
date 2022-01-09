/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** victory
*/

#include "my_runner.h"
#include <stdlib.h>

void set_vic_font(entity_t *entity, int Tsize, int Dsize)
{
    sfText_setFont(entity->menu->title, entity->menu->font);
    sfText_setFont(entity->menu->desc, entity->menu->font);
    sfText_setString(entity->menu->title, "Victory !");
    sfText_setString(entity->menu->desc,
    "Press 'r' to replay or 'q' to leave");
    sfText_setPosition(entity->menu->title, entity->menu->titlePos);
    sfText_setPosition(entity->menu->desc, entity->menu->descPos);
    sfText_setCharacterSize(entity->menu->title, Tsize);
    sfText_setCharacterSize(entity->menu->desc, Dsize);
}

void set_vic_text(entity_t *entity)
{
    int Tsize = entity->window->width / 10;
    sfVector2f Tpos = { Tsize, entity->window->height / 10 };
    int Dsize = entity->window->width / 50;
    int Dposx = entity->window->width / 2;
    sfVector2f Dpos = { Dposx, entity->window->height - 330 };
    sfIntRect lrect = {0, 0, 580, 512};
    sfVector2f lpos = {(entity->window->width / 2) - 290,
    (entity->window->height / 2) - 256};

    entity->menu = malloc(sizeof(menu_t));
    if (entity->menu == NULL)
        return NULL;
    entity->menu->title = sfText_create();
    entity->menu->desc = sfText_create();
    entity->menu->font = sfFont_createFromFile("assets/fonts/Shrek.ttf");
    entity->menu->titlePos = Tpos;
    entity->menu->descPos = Dpos;
    entity->menu->epitech = create_object("assets/img/epi.png", lpos,
    lrect, SHREK);
    set_vic_font(entity, Tsize, Dsize);
}

void display_vic_text(entity_t *entity)
{
    sfRenderWindow_drawText(entity->window->window, entity->menu->title, NULL);
    sfRenderWindow_drawText(entity->window->window, entity->menu->desc, NULL);
}

void set_victory_element(entity_t *entity)
{
    sfIntRect shrek_vict_rect = {0, 572, 43, 39};

    set_vic_text(entity);
    entity->player->rect = shrek_vict_rect;
    sfSprite_setTextureRect(entity->player->sprite, shrek_vict_rect);
}

void in_victory_manager(entity_t *entity)
{
    set_victory_element(entity);
    while (sfRenderWindow_isOpen(entity->window->window)) {
        while (sfRenderWindow_pollEvent(entity->window->window,
        &entity->window->event))
            analyse_events(entity);
        display_vic_text(entity);
        shrek_menu_anim(entity);
        sfRenderWindow_display(entity->window->window);
        sfRenderWindow_clear(entity->window->window,
        (sfColor){22, 160, 133, 0});
    }
}
