/*
** EPITECH PROJECT, 2023
** organized
** File description:
** add.c
*/

#include <stdlib.h>
#include <string.h>
#include "../lib/my.h"
#include "../libshell/shell.h"
#include "display.h"
#include "data_info.h"
#include "data_check.h"

int add(void *data, char **args)
{
    linked_list_node_t *new_node;
    linked_list_node_t **head = (linked_list_node_t **) data;

    for (int i = 0; i < get_args_len(args); i += 2) {
        new_node = malloc(sizeof(linked_list_node_t));
        if (check_type(args[i]) == 1 || args[i + 1] == NULL)
            return 1;
        if (*head == NULL) {
            new_node->id = 0;
            new_node->next = NULL;
        } else {
            new_node->id = (*head)->id + 1;
            new_node->next = *head;
        }
        new_node->type = my_strdup(args[i]);
        new_node->name = my_strdup(args[i + 1]);
        *head = new_node;
        display_on_add(new_node);
    }
    return 0;
}

int disp(void *data, __attribute__((unused))char **args)
{
    linked_list_node_t *temp = *((linked_list_node_t **) data);

    while (temp != NULL) {
        print_node(temp);
        temp = temp->next;
    }
    return 0;
}

static int delete_item(linked_list_node_t **head, int id)
{
    linked_list_node_t *temp = *head;
    linked_list_node_t *to_delete;

    if (temp->id == id) {
        to_delete = temp;
        *head = temp->next;
        free(to_delete);
        return 0;
    }
    while (temp->next != NULL) {
        if ((temp->next)->id == id) {
            to_delete = temp->next;
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

    if (*head == NULL) {
        return 1;
    }
    for (int i = 0; args[i] != NULL; i++) {
        if (delete_item(head, my_getnbr(args[i])) == 1) {
            return 1;
        }
    }
    return 0;
}

int sort(__attribute__((unused))void *data, __attribute__((unused))char **args)
{
    return 1;
}
