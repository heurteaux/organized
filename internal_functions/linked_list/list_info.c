/*
** EPITECH PROJECT, 2023
** organized
** File description:
** list_info.c
*/

#include "list_info.h"
#include <stdbool.h>
#include "../../lib/my.h"
#include "sort/sorting.h"
#include <stdlib.h>

bool is_valid_arg(char *arg, void *data, bool is_reversed)
{
    if (my_strcmp(arg, "TYPE") == 0) {
        sort_by_type(data, is_reversed);
        return true;
    }
    if (my_strcmp(arg, "NAME") == 0) {
        sort_by_name(data, is_reversed);
        return true;
    }
    if (my_strcmp(arg, "ID") == 0) {
        sort_by_id(data, is_reversed);
        return true;
    }
    if (my_strcmp(arg, "-r") == 0) {
        return true;
    }
    return false;
}

int get_list_size(linked_list_node_t *head)
{
    linked_list_node_t *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
