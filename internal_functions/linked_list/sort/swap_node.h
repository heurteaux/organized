/*
** EPITECH PROJECT, 2023
** organized
** File description:
** swap_node.h
*/

#pragma once
#include "../../../data_structure/list_node.h"

void swap_by_id(linked_list_node_t **head);

void swap_by_name(linked_list_node_t **head);

void swap_by_type(linked_list_node_t **head);

void swap_elements(
    linked_list_node_t *first_element, linked_list_node_t *second_element);
