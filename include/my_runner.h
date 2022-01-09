/*
** EPITECH PROJECT, 2021
** runner
** File description:
** main header file
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include "struct.h"

    void error_manager(enum error_type error);

    float gen_random_float(float min, float max);

    gameobject *create_object(const char *path_to_spritesheet, \
    sfVector2f pos, sfIntRect rect, enum gameobject_type type);
    void  destroy_object(gameobject *obj);
    void start_new_round(entity_t *entity);

    int load_lord_f(entity_t *entity);
    int load_guard(entity_t *entity);
    int load_shrek(entity_t *entity);

    window_t *create_window(int height, int width);
    map_t *map_load(const char *map_path);
    void destroy_window(window_t *window);
    background *create_bkg(void);
    void destroy_bkg(background *bkg);

    entity_t *start_up(int height, int width, char *map_path, bool is_infinit);
    void start_game(entity_t *entity);
    void destroy_entity(entity_t *entity);

    void analyse_events(entity_t *entity);
    void switch_fullscreen(entity_t *entity);
    void leave_game(entity_t *entity);
    void clocker(entity_t *entity);

    void scene(entity_t *entity);
    void in_menu_manager(entity_t *entity);
    void in_game_manager(entity_t *entity);
    void in_victory_manager(entity_t *entity);
    void parallax_effect(gameobject *obj);

    void display_menu_text(entity_t *entity);
    void set_menu_text(entity_t *entity);

    void update_score(entity_t *entity);
    void display_enemys(entity_t *entity);

    void shrek_menu_anim(entity_t *entity);
    void shrek_run(gameobject *obj);
    int user_jump(entity_t *entity);
    void jump_anim(gameobject *obj, user_t *user);

    void charactere_detection(gameobject *obj, entity_t *entity);

    void lord_farquad_run(gameobject *obj);
    void guard_run(gameobject *obj);

    void display_object(gameobject *obj, window_t *window);
    void display_bkg(entity_t *entity);
    void display_menu(entity_t *entity, sfClock *clock, bool *start);

    infinmode_t *load_infinite_mode_settings(entity_t *entity);
    void destroy_infinite_mode(entity_t *entity);
    void map_destroy(entity_t *entity);
#endif /* !MY_RUNNER_H_ */
