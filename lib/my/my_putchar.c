/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include "mylib.h"

char *my_putchar(char c)
{
    write(1, &c, 1);
}
