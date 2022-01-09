/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** enemys
*/

#include "my_runner.h"

int check_enemy_pos(entity_t *entity, node_t *current_enemy)
{
    gameobject *element = current_enemy->data;
    sfVector2f pos = sfSprite_getPosition(element->sprite);

    if (pos.x < (-10 - element->speed)) {
        destroy_object(element);
        delete_node(&entity->enemies, current_enemy);
        (entity->user->score)++;
        return 1;
    }
    return 0;
}

void map_mode_enemys(entity_t *entity)
{
    map_t *map = entity->map;
    float seconds;
    sfTime time;

    time = sfClock_getElapsedTime(map->clock);
    seconds = time.microseconds / 1000000;
    if (seconds >= 1 && !map->map_ended) {
        if (map->map[map->index] == '1')
            load_guard(entity);
        else if (map->map[map->index] == '2')
            load_lord_f(entity);
        else
            map->map_ended == false;
        if (map->map[map->index] == '\0')
            map->map_ended == true;
        sfClock_restart(map->clock);
        map->index += 1;
    }
    map_ended(entity);
}

void infinite_mode_enemys(entity_t *entity)
{
    infinmode_t *obj = entity->infinite_mode_settings;
    float seconds;
    sfTime time;

    time = sfClock_getElapsedTime(obj->spawn_clock);
    seconds = time.microseconds / (1000000 * gen_random_float(1, 5));
    if (seconds >= obj->spawn_rate) {
        if (gen_random_float(0, 2) < 1)
            load_guard(entity);
        else
            load_lord_f(entity);
        sfClock_restart(obj->spawn_clock);
    }
}

void check_an_enemy(entity_t *entity, gameobject *obj)
{
    float milli_seconds;
    sfTime time;

    time = sfClock_getElapsedTime(obj->clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > obj->clock_rate) {
        charactere_detection(obj, entity);
        sfClock_restart(obj->clock);
    }
    display_object(obj, entity->window);
}

void display_enemys(entity_t *entity)
{
    node_t *enemies = entity->enemies;
    gameobject *obj;

    for (; enemies != NULL;
    enemies = enemies->next) {
        if (!enemies->data)
            continue;
        if (check_enemy_pos(entity, enemies) == 1)
            continue;
        obj = enemies->data;
        check_an_enemy(entity, obj);
    }
    back_to_start(&enemies);
    if (entity->infinite_mode)
        infinite_mode_enemys(entity);
    else
        map_mode_enemys(entity);
}
