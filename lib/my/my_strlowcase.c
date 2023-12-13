/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task08
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 64 && str[i] < 91) {
            str[i] += 32;
        }
    }
    return str;
}

/*void main()
{
    char to_uppercase[] = "AZè-(e-é_àç&_zaàçduaçdazàdç_éagsuà";
    printf("%s\n", to_uppercase);
    my_strlowcase(to_uppercase);
    printf("%s\n", to_uppercase);
    }*/
