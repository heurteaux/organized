/*
** EPITECH PROJECT, 2023
** organized
** File description:
** struct.h
*/

#pragma once

typedef struct linked_list_node_s {
    char *type;
    char *name;
    int id;
    struct linked_list_node_s *next;
}linked_list_node_t;
