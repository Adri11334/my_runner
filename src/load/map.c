/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** map
*/

#include <fcntl.h>

#include "my_runner.h"

int is_valid_map(char const *path)
{
    char *map = malloc(sizeof(char) * 100000);
    int fd;
    int rd;

    if (path == NULL || map == NULL)
        return (1);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (-1);
    rd = read(fd, map, 100000);
    map[rd] = '\0';
    close(fd);
    for (int i = 0; map[i]; i++)
        if (map[i] != '1' && map[i] != '2' && map[i] != ' ')
            return (-1);
    free(map);
    return (0);
}

int map_length(const char *path)
{
    char *map = malloc(sizeof(char) * 100000);
    int fd;
    int rd;

    if (path == NULL || map == NULL)
        return (1);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (1);
    rd = read(fd, map, 100000);
    map[rd] = '\0';
    close(fd);
    free(map);
    return (rd);
}

char *get_map(char const *path)
{
    int length = map_length(path);
    char *map = my_malloc(sizeof(char) * length + 1, NULL);
    int fd;
    int rd;

    if (path == NULL || map == NULL)
        return NULL;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return NULL;
    rd = read(fd, map, length + 1);
    close(fd);
    return (map);
}

map_t *map_load(const char *map_path)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL)
        return NULL;
    map->map = get_map(map_path);
    if (map->map == NULL)
        return NULL;
    map->index = 0;
    map->displayed_enemies = 0;
    map->map_ended = false;
    map->clock = sfClock_create();
    map->clock_rate = 10;
    map->speed = 100;
    return (map);
}

void map_destroy(entity_t *entity)
{
    if (entity->infinite_mode)
        return;
    my_printf("Destroying game map...\n");
    sfClock_destroy(entity->map->clock);
    my_printf("Destroying map model stock...\n");
    free(entity->map->map);
    my_printf("Destroying map struct...\n");
    free(entity->map);
}
