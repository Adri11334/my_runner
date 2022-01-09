/*
** EPITECH PROJECT, 2021
** bs_myrunner
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "enum.h"
    #include "stdbool.h"
    #include "my.h"

    typedef struct gameobject_s {
        enum gameobject_type type;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfIntRect rect;
        sfClock *clock;
        float clock_rate;
        int speed;
    } gameobject;

    typedef struct window_s {
        sfRenderWindow* window;
        sfMusic *main_audio;
        bool is_fullscreen;
        enum gamestatus stat;
        sfEvent event;
        int height;
        int width;
    } window_t;

    typedef struct map_s {
        char *map;
        int index;
        int displayed_enemies;
        bool map_ended;
        sfClock *clock;
        float clock_rate;
        int speed;
    } map_t;

    typedef struct bkg_s {
        gameobject *layer1;
        gameobject *layer2;
        gameobject *layer3;
        gameobject *layer4;
        gameobject *layer5;
    } background;

    typedef struct user_s {
        int best_score;
        int score;
        bool is_jumping;
        bool is_down_jumping;
        int actual_jump_height;
        int base_player_height;
        sfMusic *jump;
        sfText *score_txt;
    } user_t;

    typedef struct menu_s {
        gameobject *epitech;
        sfText *title;
        sfText *desc;
        sfFont *font;
        sfVector2f titlePos;
        sfVector2f descPos;
    } menu_t;

    typedef struct infin_mode_s {
        sfClock *score_clock;
        sfClock *spawn_clock;
        float spawn_rate;
    } infinmode_t;

    typedef struct entity_s {
        gameobject *player;
        node_t *enemies;
        background *bkg;
        window_t *window;
        map_t *map;
        user_t *user;
        menu_t *menu;
        bool infinite_mode;
        infinmode_t *infinite_mode_settings;
    } entity_t;
#endif /* !STRUCT_H_ */
