/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sorting_functions_rev.c
*/

#include "../data_structure/struct.h"
#include <stdlib.h>
#include "sorting.h"
#include "../lib/my.h"

void swap_by_id_reversed(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (temp->id < temp->next->id) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void swap_by_name_reversed(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (my_strcmp(temp->name, (temp->next)->name) < 0) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void swap_by_type_reversed(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (my_strcmp(temp->type, (temp->next)->type) < 0) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}
