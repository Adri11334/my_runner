/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu
*/

#include "my_runner.h"

void display_menu(entity_t *entity, sfClock *clock, bool *start)
{
    sfTime time;
    float milli_seconds;

    time = sfClock_getElapsedTime(clock);
    milli_seconds = time.microseconds / 1000;
    display_object(entity->menu->epitech, entity->window);
    sfRenderWindow_display(entity->window->window);
    if (milli_seconds > 2650) {
        (*start) = true;
        sfClock_restart(clock);
    }
}

void set_font(entity_t *entity, int Tsize, int Dsize)
{
    sfText_setFont(entity->menu->title, entity->menu->font);
    sfText_setFont(entity->menu->desc, entity->menu->font);
    sfText_setString(entity->menu->title, "My Shrek");
    sfText_setString(entity->menu->desc, "Press 'S' to play");
    sfText_setPosition(entity->menu->title, entity->menu->titlePos);
    sfText_setPosition(entity->menu->desc, entity->menu->descPos);
    sfText_setCharacterSize(entity->menu->title, Tsize);
    sfText_setCharacterSize(entity->menu->desc, Dsize);
}

void set_menu_text(entity_t *entity)
{
    int Tsize = entity->window->width / 10;
    sfVector2f Tpos = { Tsize, entity->window->height / 10 };
    int Dsize = entity->window->width / 40;
    int Dposx = entity->window->width / 2;
    sfVector2f Dpos = { Dposx, entity->window->height - 330 };
    sfIntRect lrect = {0, 0, 580, 512};
    sfVector2f lpos = {(entity->window->width / 2) - 290, \
    (entity->window->height / 2) - 256};

    entity->menu = malloc(sizeof(menu_t));
    if (entity->menu == NULL)
        return NULL;
    entity->menu->title = sfText_create();
    entity->menu->desc = sfText_create();
    entity->menu->font = sfFont_createFromFile("assets/fonts/Shrek.ttf");
    entity->menu->titlePos = Tpos;
    entity->menu->descPos = Dpos;
    entity->menu->epitech = create_object("assets/img/epi.png", lpos, \
    lrect, SHREK);
    set_font(entity, Tsize, Dsize);
}

void display_menu_text(entity_t *entity)
{
    sfRenderWindow_drawText(entity->window->window, entity->menu->title, NULL);
    sfRenderWindow_drawText(entity->window->window, entity->menu->desc, NULL);
}
