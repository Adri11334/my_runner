/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** create
*/

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// Init a new double linked list with a start of Data
//
// @param data the pointer to the data we need to push
////////////////////////////////////////////////////////////
node_t *init_list(void *data)
{
    node_t *list = malloc(sizeof(node_t));

    if (list == NULL)
        return NULL;
    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}
