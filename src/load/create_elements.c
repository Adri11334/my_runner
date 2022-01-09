/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** create_elements
*/

#include "my_runner.h"

char *get_map(char const *path);

window_t *create_window(int height, int width)
{
    window_t *window = malloc(sizeof(window_t));
    sfVideoMode mode = { width, height, 32 };

    if (window == NULL)
        return NULL;
    window->height = height;
    window->width = width;
    window->window = sfRenderWindow_create(mode, "SHREK 4",
    sfFullscreen, NULL);
    window->stat = MENU;
    window->is_fullscreen = true;
    sfRenderWindow_setFramerateLimit(window->window, 45);
    return window;
}

void destroy_window(window_t *window)
{
    sfRenderWindow_destroy((*window).window);
    free(window);
}

void set_bg_speed(background *bkg)
{
    bkg->layer2->speed = 5;
    bkg->layer2->clock_rate = 10;
    bkg->layer3->speed = 7;
    bkg->layer3->clock_rate = 5;
    bkg->layer5->speed = 15;
    bkg->layer5->clock_rate = .2;
}

background *create_bkg(void)
{
    background *bkg = malloc(sizeof(background));
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 3840, 1080};
    char layer2[] = "assets/img/background/BG_Decor.png";
    char layer3[] = "assets/img/background/Middle_Decor.png";
    char layer5[] = "assets/img/background/Ground.png";

    if (bkg == NULL)
        return NULL;
    bkg->layer2 = create_object(layer2, pos, rect, BKG);
    if (bkg->layer2 == NULL)
        return NULL;
    bkg->layer3 = create_object(layer3, pos, rect, BKG);
    if (bkg->layer3 == NULL)
        return NULL;
    bkg->layer5 = create_object(layer5, pos, rect, BKG);
    if (bkg->layer5 == NULL)
        return NULL;
    set_bg_speed(bkg);
    return bkg;
}

void destroy_bkg(background *bkg)
{
    destroy_object(bkg->layer2);
    destroy_object(bkg->layer3);
    destroy_object(bkg->layer5);
    free(bkg);
}
