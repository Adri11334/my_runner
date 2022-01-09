/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** analyse events
*/

#include "my_runner.h"

void restart_game(entity_t *entity);

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void key_filter(entity_t *entity, sfKeyEvent event)
{
    if (event.code == sfKeyF)
        switch_fullscreen(entity);
    if (event.code == sfKeyEscape || event.code == sfKeyQ)
        leave_game(entity);
    if (entity->window->stat == PLAYING)
        if (event.code == sfKeySpace)
            user_jump(entity);
    if (entity->window->stat == MENU)
        if (event.code == sfKeyS)
            start_game(entity);
    if (entity->window->stat == VICTORY || entity->window->stat == DEAD)
        if (event.code == sfKeyR)
            restart_game(entity);
}

void analyse_events(entity_t *entity)
{
    if (entity->window->event.type == sfEvtClosed)
        close_window(entity->window->window);
    if (entity->window->event.type == sfEvtKeyPressed)
        key_filter(entity, entity->window->event.key);
}
