/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** print
*/

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// Get the size of a double linked list
//
// @param node the pointer to the linked list
////////////////////////////////////////////////////////////
int node_length(node_t *node)
{
    int length = 0;

    for (; node != NULL; length++)
        node = node->next;
    return length;
}
