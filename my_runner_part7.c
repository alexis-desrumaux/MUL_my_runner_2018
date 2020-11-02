/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part7.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int start_runner(window_t *window)
{
    int check = 0;

    if (window->event.mouseButton.x >= 721 &&
    window->event.mouseButton.x <= 1100
    && window->event.mouseButton.y >= 813
    && window->event.mouseButton.y <= 970) {
        check = 2;
    }
    return (check);
}

void surprised_obelix_part5(window_t *window)
{
    if (window->obelix.position_sco == 3) {
        window->obelix.rect.left = 1787;
        window->obelix.rect.width = 145;
        window->obelix.rect.top = 32;
        window->obelix.rect.height = 207;
    }
}

void surprised_obelix_part4(window_t *window)
{
    switch (window->obelix.position_sco)
    {
        case 1:
            window->obelix.rect.left = 1447;
            window->obelix.rect.width = 142;
            window->obelix.rect.top = 30;
            window->obelix.rect.height = 212;
            break;
        case 2:
            window->obelix.rect.left = 1619;
            window->obelix.rect.width = 136;
            window->obelix.rect.top = 30;
            window->obelix.rect.height = 210;
            break;
    }
    if (window->obelix.position_sco > 2)
    surprised_obelix_part5(window);
}

void surprised_obelix_part3(window_t *window)
{
    switch (window->obelix.position_so)
    {
        case 3:
            window->obelix.rect.left = 218;
            window->obelix.rect.width = 128;
            window->obelix.rect.top = 1146;
            window->obelix.rect.height = 206;
            break;
        case 4:
            window->obelix.rect.left = 810;
            window->obelix.rect.width = 106;
            window->obelix.rect.top = 878;
            window->obelix.rect.height = 200;
            break;
    }
}

void surprised_obelix_part2(window_t *window)
{
    switch (window->obelix.position_so)
    {
        case 1:
            window->obelix.rect.left = 44;
            window->obelix.rect.width = 124;
            window->obelix.rect.top = 1144;
            window->obelix.rect.height = 240;
            break;
        case 2:
            window->obelix.rect.left = 372;
            window->obelix.rect.width = 142;
            window->obelix.rect.top = 1148;
            window->obelix.rect.height = 204;
            break;
    }
    if (window->obelix.position_so > 2)
    surprised_obelix_part3(window);
}
