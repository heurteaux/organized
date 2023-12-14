/*
** EPITECH PROJECT, 2023
** organized
** File description:
** display.c
*/

#include "display.h"
#include "../../../lib/my.h"

void display_on_add(linked_list_node_t *node)
{
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\" added.\n");
}

void display_on_delete(linked_list_node_t *node)
{
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\" deleted.\n");
}

void print_node(linked_list_node_t *node)
{
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\"\n");
}
