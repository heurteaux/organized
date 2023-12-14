/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sorting.c
*/

#include "sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include "../lib/my.h"
#include "sorting_functions_rev.h"

static int get_list_size(linked_list_node_t *head)
{
    linked_list_node_t *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void swap_elements(
    linked_list_node_t *first_element, linked_list_node_t *second_element)
{
    linked_list_node_t temp = *first_element;

    *first_element = *second_element;
    *second_element = temp;
    second_element->next = first_element->next;
    first_element->next = second_element;
}

static void swap_by_type(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (my_strcmp(temp->type, (temp->next)->type) > 0) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void sort_by_type(void *data, bool is_reversed)
{
    linked_list_node_t **head = (linked_list_node_t **) data;

    for (int i = 0; i <= get_list_size(*head); i++) {
        if (!is_reversed)
            swap_by_type(head);
        else
            swap_by_type_reversed(head);
    }
}

static void swap_by_name(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (my_strcmp(temp->name, (temp->next)->name) > 0) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void sort_by_name(void *data, bool is_reversed)
{
    linked_list_node_t **head = (linked_list_node_t **) data;

    for (int i = 0; i <= get_list_size(*head); i++) {
        if (!is_reversed)
            swap_by_name(head);
        else
            swap_by_name_reversed(head);
    }
}

static void swap_by_id(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;

    while (temp->next != NULL) {
        if (temp->id > temp->next->id) {
            swap_elements(temp, temp->next);
        }
        temp = temp->next;
    }
}

void sort_by_id(void *data, bool is_reversed)
{
    linked_list_node_t **head = (linked_list_node_t **) data;

    for (int i = 0; i <= get_list_size(*head); i++) {
        if (!is_reversed)
            swap_by_id(head);
        else
            swap_by_id_reversed(head);
    }
}
