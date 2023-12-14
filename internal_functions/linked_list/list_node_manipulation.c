/*
** EPITECH PROJECT, 2023
** organized
** File description:
** list_node_manipulation.c
*/

#include <stdlib.h>
#include "display/display.h"
#include "../../data_structure/list_node.h"

void delete_head_element(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;
    linked_list_node_t *to_delete = temp;

    display_on_delete(to_delete);
    *head = temp->next;
    free(to_delete);
}

int delete_item(linked_list_node_t **head, int id)
{
    linked_list_node_t *temp = *head;
    linked_list_node_t *to_delete;

    if (temp->id == id) {
        delete_head_element(head);
        return 0;
    }
    while (temp->next != NULL) {
        if ((temp->next)->id == id) {
            to_delete = temp->next;
            display_on_delete(to_delete);
            temp->next = temp->next->next;
            free(to_delete);
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}
