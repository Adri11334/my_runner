/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** destroy
*/

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// Destroy a linked list (will not destroy his content)
//
// @param node the pointeur to the linked list
////////////////////////////////////////////////////////////
void destroy_node(node_t **node)
{
    node_t *current = *node;

    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}
