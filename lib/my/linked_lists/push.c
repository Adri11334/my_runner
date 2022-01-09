/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** push
*/

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// Put a Data at the head of a double linked list
//
// @param node the node to insert the data
//
// @param data the pointer to the data we need to push
////////////////////////////////////////////////////////////
void push_node(node_t **node, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return NULL;
    new_node->data = data;
    new_node->next = *node;
    new_node->prev = NULL;
    if ((*node) != NULL)
        (*node)->prev = new_node;
    (*node) = new_node;
}
