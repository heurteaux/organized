/*
** EPITECH PROJECT, 2023
** organized
** File description:
** add.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my.h"
#include "../libshell/shell.h"
#include "args/data_check.h"
#include "args/data_info.h"
#include "linked_list/create_node.h"
#include "linked_list/display/display.h"
#include "linked_list/list_info.h"
#include "linked_list/list_node_manipulation.h"

int add(void *data, char **args)
{
    linked_list_node_t *new_node;
    linked_list_node_t **head = (linked_list_node_t **) data;

    if (get_args_len(args) < 1)
        return 84;
    for (int i = 0; i < get_args_len(args); i += 2) {
        new_node = malloc(sizeof(linked_list_node_t));
        if (check_type(args[i]) == 1 || args[i + 1] == NULL)
            return 84;
        setup_new_node(new_node, head, i, args);
    }
    return 0;
}

int disp(void *data, __attribute__((unused)) char **args)
{
    linked_list_node_t *temp = *((linked_list_node_t **) data);

    while (temp != NULL) {
        print_node(temp);
        temp = temp->next;
    }
    return 0;
}

int del(void *data, char **args)
{
    linked_list_node_t **head = (linked_list_node_t **) data;

    if (get_args_len(args) < 1)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (*head == NULL || my_getnbr(args[i]) == (-1)) {
            return 84;
        }
        if (delete_item(head, my_getnbr(args[i])) == 1) {
            return 84;
        }
    }
    return 0;
}

int sort(void *data, char **args)
{
    bool is_reversed = false;

    if (*(linked_list_node_t **)data == NULL)
        return 0;
    for (int i = get_args_len(args) - 1; i >= 0; i--) {
        if (args[i + 1] != NULL)
            is_reversed = (my_strcmp(args[i + 1], "-r") == 0);
        if (is_valid_arg(args[i], data, is_reversed)) {
            is_reversed = false;
            continue;
        }
        return 84;
    }
    return 0;
}
