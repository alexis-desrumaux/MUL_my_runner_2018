/*
** EPITECH PROJECT, 2018
** my_putint.c
** File description:
** my_putint.c
*/

#include "mylib.h"
#include <stdlib.h>

long f_conversion(int check, char *str, long value, long zero)
{
    long i = 0;

    while (str[i] != '\0') {
        value += (str[i] - 48) * zero;
        zero /= 10;
        i++;
    }
    value /= 10;
    if (check == 1)
    value = value * -1;
    return (value);
}

char *isneg(char *str)
{
    long i = 1;
    long k = 0;
    long l = 1;
    char *newstr = malloc(sizeof(str) * 4);

    while (str[i] != '\0') {
        newstr[k] = str[i];
        i++;
        k++;
        l++;
    }
    newstr[k] = '\0';
    return (newstr);
}

long my_putint(char *str)
{
    long value = 0;
    long zero = 1;
    long i = 0;
    int check = 0;

    if (str[0] == '-') {
        str = isneg(str);
        check = 1;
    }
    while (str[i] != '\0') {
        zero *= 10;
        i++;
    }
    i = 0;
    value = f_conversion(check, str, value, zero);
    return (value);
}
