/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sorting.c
*/

#include "sorting.h"
#include <stdbool.h>
#include "sorting_functions_rev.h"
#include "swap_node.h"
#include "../list_info.h"

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
