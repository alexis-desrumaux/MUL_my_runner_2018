/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** XYZ_BSQ.c
*/

#include "mylib.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int f_lignebsq(int x, int y, int x1, int p)
{
    int i = x1+1;
    int j = 0;
    int c = 0;

    while (j < p) {
        j = j + x;
        c++;
    }
    c = c - 1;
    c = c + x1;
    return (c);
}

int f_x_bsq(int bytes, char *path)
{
    int i = 0;
    int j = 0;
    int fd;
    char *buff = malloc(5000);

    fd = open(path, O_RDWR);
    read(fd, buff, bytes);
    while (buff[i] != '\n') {
        i++;
    }
    i = i + 1;
    while (buff[i] != '\n') {
        j++;
        i++;
    }
    close(fd);
    return (j);
}

int f_x1_bsq(int bytes, char *path)
{
    int i = 0;
    int fd;
    char *buff = malloc(5000);

    fd = open(path, O_RDWR);
    read(fd, buff, bytes);
    while (buff[i] != 10) {
        i++;
        if (buff[i] == 0)
        return (i);
    }
    return (i);
    close(fd);
}

int f_y_bsq(int bytes, char *path)
{
    int i = 0;
    int fd;
    int y = 0;
    char *buff = malloc(5000);
    char *newstr = malloc(5000);

    fd = open(path, O_RDWR);
    read(fd, buff, bytes);
    while (buff[i] != 10) {
        newstr[i] = buff[i];
        if (buff[i] == 0) {
        newstr[i] = '\0';
        buff[i+1] = 10;
        }
        i++;
    }
    newstr[i] = '\0';
    y = my_putint(newstr);
    close(fd);
    return (y);
}
