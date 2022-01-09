/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** jumping
*/

#include "my_runner.h"

int user_jump(entity_t *entity)
{
    if (entity->user->is_jumping) {
        write_red("[input] jumping key received but not able.\n");
        return -1;
    }
    write_cyan("[input] jumping key received in valid time.\n");
    entity->user->base_player_height =
    sfSprite_getPosition(entity->player->sprite).y;
    entity->user->is_jumping = true;
    sfMusic_setPlayingOffset(entity->user->jump, sfTime_Zero);
    sfMusic_play(entity->user->jump);
    return 0;
}
