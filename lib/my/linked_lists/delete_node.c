/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** delete_mode
*/

#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// delete a node in a double linked list
//
// @param node the pointer to the linked list
//
// @param to_delete the pointer to the node to delete
////////////////////////////////////////////////////////////
void delete_node(node_t **node, node_t *to_delete)
{
    if ((*node) == NULL || to_delete == NULL)
        return;
    if ((*node) == to_delete)
        (*node) = to_delete->next;
    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
    if (to_delete->next != NULL)
        to_delete->next->prev = to_delete->prev;
    free(to_delete);
}
