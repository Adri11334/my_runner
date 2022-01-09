/*
** EPITECH PROJECT, 2021
** my_runner [WSL: Ubuntu]
** File description:
** load_up
*/

#include "my_runner.h"

user_t *load_user_data(void);
infinmode_t *load_infinite_mode_settings(entity_t *entity);

int set_game_mode(entity_t *entity, char *map_path, bool infinite_mode)
{
    my_printf("Loading map...\n");
    entity->infinite_mode = infinite_mode;
    if (infinite_mode) {
        entity->infinite_mode_settings = load_infinite_mode_settings(entity);
        if (entity->infinite_mode_settings == NULL)
            return 84;
    } else {
        entity->map = map_load(map_path);
        if (entity->map == NULL)
            return 84;
    }
}

entity_t *start_up(int height, int width, char *map_path, bool infinite_mode)
{
    entity_t *entity = malloc(sizeof(entity_t));
    char music_path[] = "assets/audio/menu.ogg";

    if (entity == NULL)
        return NULL;
    red_header("LOADING GAME ELEMENTS");
    entity->bkg = create_bkg();
    if (load_shrek(entity) == 84)
        return NULL;
    entity->enemies = init_list(NULL);
    entity->window = create_window(height, width);
    entity->user = load_user_data();
    entity->window->main_audio = sfMusic_createFromFile(music_path);
    sfMusic_setLoop(entity->window->main_audio, sfTrue);
    if (set_game_mode(entity, map_path, infinite_mode) == 84)
        return NULL;
    write_green("[V] Elements loaded.\n");
    return entity;
}

void destroy_window_sound(entity_t *entity)
{
    my_printf("Destroying game audio...\n");
    if (entity->window->main_audio) {
        sfMusic_stop(entity->window->main_audio);
        sfMusic_destroy(entity->window->main_audio);
    }
    destroy_window(entity->window);
    map_destroy(entity);
}

void destroy_enemies(node_t *enemies)
{
    gameobject *obj;

    for (int i = 0; enemies != NULL && enemies->data != NULL; i++) {
        obj = enemies->data;
        destroy_object(obj);
        enemies = enemies->next;
    }
    back_to_start(&enemies);
    destroy_node(&enemies);
}

void destroy_entity(entity_t *entity)
{
    red_header("DESTROYING GAME ELEMENTS");
    destroy_bkg(entity->bkg);
    destroy_enemies(entity->enemies);
    destroy_object(entity->player);
    sfMusic_stop(entity->user->jump);
    sfMusic_destroy(entity->user->jump);
    sfText_destroy(entity->user->score_txt);
    free(entity->user);
    destroy_window_sound(entity);
    destroy_infinite_mode(entity);
    free(entity);
    write_green("[V] Game Destroyed.\n");
}
