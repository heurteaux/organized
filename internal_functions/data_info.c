/*
** EPITECH PROJECT, 2023
** organized
** File description:
** data_info.c
*/

#include "data_info.h"
#include <stdlib.h>

int get_args_len(char **args)
{
    int i = 0;

    while (args[i] != NULL) {
        i++;
    }
    return i;
}
