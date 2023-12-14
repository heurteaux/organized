/*
** EPITECH PROJECT, 2023
** organized
** File description:
** list_info.h
*/

#pragma once
#include <stdbool.h>
#include "../../data_structure/list_node.h"

bool is_valid_arg(char *arg, void *data, bool is_reversed);

int get_list_size(linked_list_node_t *head);
