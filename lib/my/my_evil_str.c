/*
** EPITECH PROJECT, 2023
** Day04
** File description:
** task04
*/

#include "my.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    char holder;
    int inv_len;

    for (int i = 0; i < len / 2; i++) {
        inv_len = len - i - 1;
        holder = str[inv_len];
        str[inv_len] = str[i];
        str[i] = holder;
    }
    return &str[0];
}

/*void main()
{
    char str_test[] = "Sir, yes sir !";
    char *test = my_evil_str(&str_test);
    my_putstr(test);
    }*/
