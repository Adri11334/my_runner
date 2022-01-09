/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** pre_loading
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

entity_t *start_up(int height, int width, char const *map_path, bool infin);
void destroy_entity(entity_t *entity);
int is_valid_map(char const *path);
void scene(entity_t *entity);

int check_arguments(char const* const* argv, entity_t *entities, int w, int h)
{
    if (my_strcmp(argv[1], "-h") == 0) {
        free(entities);
        return display_help();
    } else if (is_valid_map(argv[1]) != -1) {
        write_green("[V] Map received and look valid.\n");
        write_green("Starting program with this map\n");
        entities = start_up(w, h, argv[1], false);
        scene(entities);
        destroy_entity(entities);
        return 0;
    } else {
        write_red("[X] Warning: no or invalid map provided.\n");
        write_red("You will start in infinit mode.\n");
        entities = start_up(w, h, argv[1], true);
        scene(entities);
        destroy_entity(entities);
        return 0;
    }
}

int start_program(int argc, char const* const* argv)
{
    int width = (argc == 3) ? my_getnbr(argv[1]) : 1050;
    int height = (argc == 3) ? my_getnbr(argv[2]) : 1920;
    entity_t *entities = malloc(sizeof(entity_t));

    if (argc > 1) {
        return check_arguments(argv, entities, width, height);
    } else {
        write_red("[X] Warning: no map provided.\n");
        write_red("You will start in infinit mode.\n");
        entities = start_up(width, height, "", true);
        scene(entities);
        destroy_entity(entities);
        return 0;
    }
    return 84;
}
