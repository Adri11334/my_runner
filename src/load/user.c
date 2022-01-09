/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** user
*/

#include "my_runner.h"

user_t *load_user_data(void)
{
    user_t *user = malloc(sizeof(user_t));
    sfFont *font = sfFont_createFromFile("assets/fonts/Shrek.ttf");

    user->score = 0;
    user->best_score = 0;
    user->actual_jump_height = 0;
    user->base_player_height = 0;
    user->is_jumping = false;
    user->is_down_jumping = false;
    user->jump = sfMusic_createFromFile("assets/audio/jump.ogg");
    sfMusic_pause(user->jump);
    user->score_txt = sfText_create();
    sfText_setFont(user->score_txt, font);
    return user;
}
