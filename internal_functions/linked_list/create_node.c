/*
** EPITECH PROJECT, 2023
** organized
** File description:
** create_node.c
*/

#include "create_node.h"
#include <stdlib.h>
#include "../../lib/my.h"
#include "display/display.h"

void setup_new_node(linked_list_node_t *new_node,
    linked_list_node_t **head, int i, char **args)
{
    static int max_id = 0;

    if (*head == NULL) {
        new_node->id = 0;
        new_node->next = NULL;
    } else {
        max_id++;
        new_node->id = max_id;
        new_node->next = *head;
    }
    new_node->type = my_strdup(args[i]);
    new_node->name = my_strdup(args[i + 1]);
    *head = new_node;
    display_on_add(new_node);
}
