/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** restart
*/

////////////////////////////////////////////////////////////
//
// Get back to the first position of the linked list
//
// @param data the pointeur to the data we need to push
////////////////////////////////////////////////////////////

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// Get back to the first pos of a linked list
//
// @param node the pointer to the linked list
////////////////////////////////////////////////////////////
void back_to_start(node_t **node)
{
    if ((*node) == NULL)
        return NULL;
    while ((*node)->prev != NULL)
        *node = (*node)->prev;
}
