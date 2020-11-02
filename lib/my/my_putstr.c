/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr function
*/

#include "mylib.h"

char my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
