/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** get_strarg_int.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

char *recup_int_strarg(char *strarg, int k)
{
    char *str = malloc(sizeof(strarg));
    int i = 0;

    while (strarg[k] != '#') {
        str[i] = strarg[k];
        k++;
        i++;
    }
    str[k] = '\0';
    return (str);
}

int get_strarg_int(char *strarg, int nbarg)
{
    int i = 0;
    int j = 0;
    int nb = 0;
    int check = 0;
    int lastarg = 0;

    if (nbarg == 1)
    strarg = recup_int_strarg(strarg, 0);
    else if (nbarg > 1) {
        while (strarg[i] != '\0' && j != nbarg - 1) {
            if (strarg[i] == '#') {
                j++;
                lastarg = i;
            }
            i++;
        }
        strarg = recup_int_strarg(strarg, lastarg + 1);
    }
    nb = my_putint(strarg);
    return (nb);
}
