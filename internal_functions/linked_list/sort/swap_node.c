/*
** EPITECH PROJECT, 2023
** organized
** File description:
** swap_node.c
*/

#include "swap_node.h"
#include "../../../lib/my.h"
#include <stdlib.h>

void swap_elements(
    linked_list_node_t *first_element, linked_list_node_t *second_element)
{
    linked_list_node_t temp = *first_element;

    *first_element = *second_element;
    *second_element = temp;
    second_element->next = first_element->next;
    first_element->next = second_element;
}

void swap_by_type(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (my_strcmp(temp->type, (temp->next)->type) > 0) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void swap_by_name(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (my_strcmp(temp->name, (temp->next)->name) > 0) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void swap_by_id(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (temp->id > temp->next->id) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}
