/*
** EPITECH PROJECT, 2021
** runner
** File description:
** parallax gestion
*/

#include "my_runner.h"

void parallax_effect(gameobject *bkg)
{
    if (bkg->rect.left + bkg->speed < 1920)
        bkg->rect.left += bkg->speed;
    else
        bkg->rect.left = 0;
    sfSprite_setTextureRect(bkg->sprite, bkg->rect);
}
