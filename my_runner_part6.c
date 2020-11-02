/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part6.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void surprised_obelix(window_t *window, int option)
{
    if (option == 1) {
    surprised_obelix_part2(window);
    if (window->obelix.position_so != 5)
    window->obelix.position_so++;
    }
    else if (option == 2) {
    surprised_obelix_part4(window);
    if (window->obelix.position_sco != 4)
    window->obelix.position_sco++;
    else if (window->obelix.position_sco == 4)
    window->obelix.position_sco = 1;
    }
}

void walking_obelix_part3(window_t *window)
{
    switch (window->obelix.position_o)
    {
        case 4:
            window->obelix.rect.left = 1042;
            window->obelix.rect.width = 104;
            break;
        case 5:
            window->obelix.rect.left = 1186;
            window->obelix.rect.width = 104;
            break;
        case 6:
            window->obelix.rect.left = 1314;
            window->obelix.rect.width = 104;
            break;
    }
}

void walking_obelix_part2(window_t *window)
{
    switch (window->obelix.position_o)
    {
        case 1:
            window->obelix.rect.left = 638;
            window->obelix.rect.width = 100;
            break;
        case 2:
            window->obelix.rect.left = 772;
            window->obelix.rect.width = 104;
            break;
        case 3:
            window->obelix.rect.left = 912;
            window->obelix.rect.width = 104;
            break;
    }
    if (window->obelix.position_o > 3)
    walking_obelix_part3(window);
}

int walking_obelix(window_t *window)
{
    walking_obelix_part2(window);
    if (window->obelix.position_o != 5)
    window->obelix.position_o++;
    else if (window->obelix.position_o == 5)
    window->obelix.position_o = 1;
}

int manage_event_runner_part2(window_t *window)
{
    if (window->event.type == sfEvtKeyPressed) {
        if (window->event.key.code == sfKeyRight)
        window->runner.forest.vitesse++;
        else if ((window->event.key.code == sfKeyLeft))
        if (window->runner.forest.vitesse > 0)
        window->runner.forest.vitesse--;
    }
}
