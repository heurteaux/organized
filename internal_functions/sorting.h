/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sorting.h
*/

#pragma once
#include <stdbool.h>
#include "../data_structure/struct.h"

void sort_by_type(void *data, bool is_reversed);

void sort_by_name(void *data, bool is_reversed);

void sort_by_id(void *data, bool is_reversed);

void swap_elements(
    linked_list_node_t *first_element, linked_list_node_t *second_element);
