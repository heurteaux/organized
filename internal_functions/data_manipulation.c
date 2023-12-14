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
#include "display.h"
#include "sorting.h"
#include "data_check.h"
#include "data_info.h"

static void setup_new_node(linked_list_node_t *new_node,
    linked_list_node_t **head, int i, char **args)
{
    static int max_id = 0;

    if (*head == NULL) {
        new_node->id = 0;
        new_node->next = NULL;
    } else {
        max_id++;
        new_node->id = max_id;
        new_node->next = *head;
    }
    new_node->type = my_strdup(args[i]);
    new_node->name = my_strdup(args[i + 1]);
    *head = new_node;
    display_on_add(new_node);
}

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

static void delete_head_element(linked_list_node_t **head)
{
    linked_list_node_t *temp = *head;
    linked_list_node_t *to_delete = temp;

    display_on_delete(to_delete);
    *head = temp->next;
    free(to_delete);
}

static int delete_item(linked_list_node_t **head, int id)
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

static bool is_valid_arg(char *arg, void *data, bool is_reversed)
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
