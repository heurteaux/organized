/*
** EPITECH PROJECT, 2023
** organized
** File description:
** reverse.c
*/

#include "reverse.h"
#include <stdlib.h>

void reverse(linked_list_node_t **head)
{
    linked_list_node_t *prev = NULL;
    linked_list_node_t *current = *head;
    linked_list_node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
