/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** score
*/

#include "my_runner.h"

void update_score(entity_t *entity)
{
    sfText_setPosition(entity->user->score_txt, (sfVector2f){200, 100});
    sfText_setCharacterSize(entity->user->score_txt, 40);
    sfText_setString(entity->user->score_txt, my_to_str(entity->user->score));
    sfRenderWindow_drawText(entity->window->window,
    entity->user->score_txt, NULL);
    return;
}
