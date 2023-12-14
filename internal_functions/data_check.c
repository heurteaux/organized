/*
** EPITECH PROJECT, 2023
** organized
** File description:
** data_check.c
*/

#include "../lib/my.h"
#include <malloc.h>

int check_type(char *type)
{
    char **possible_types = malloc(sizeof(char *) * 6);

    possible_types[0] = "ACTUATOR";
    possible_types[1] = "DEVICE";
    possible_types[2] = "PROCESSOR";
    possible_types[3] = "SENSOR";
    possible_types[4] = "WIRE";
    possible_types[5] = NULL;
    for (int i = 0; possible_types[i] != NULL; i++) {
        if (my_strcmp(type, possible_types[i]) == 0)
            return 0;
    }
    return 1;
}
