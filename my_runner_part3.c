/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part3.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void middle_f(window_t *window)
{
    if (window->runner.middle.seconds_m > 0.07)
    {
        if (window->runner.middle.position2.x < window->obelix.position.x - 1000
        && window->runner.middle.check == 1)
        {
            window->runner.middle.position.x += 3520;
            window->runner.middle.check = 2;
        }
        if (window->runner.middle.position.x < window->obelix.position.x - 1000
        && window->runner.middle.check == 2)
        {
            window->runner.middle.position2.x += 3520;
            window->runner.middle.check = 1;
        }
        middle_f2(window);
    }
}

void ciel_f2(window_t *window)
{
    window->runner.ciel.position.x -= 2;
    window->runner.ciel.position2.x -= 2;
    sfSprite_setPosition(window->runner.ciel.sprite,
    window->runner.ciel.position);
    sfSprite_setPosition(window->runner.ciel.sprite2,
    window->runner.ciel.position2);
    sfClock_restart(window->runner.ciel.clock_b);
}

void ciel_f(window_t *window)
{
    if (window->runner.ciel.seconds_b > 0.1) {
        if (window->runner.ciel.position2.x < window->obelix.position.x - 1000
        && window->runner.ciel.check == 1)
        {
            window->runner.ciel.position.x += 11520;
            window->runner.ciel.check = 2;
        }
        if (window->runner.ciel.position.x < window->obelix.position.x - 1000
        && window->runner.ciel.check == 2)
        {
            window->runner.ciel.position2.x += 11520;
            window->runner.ciel.check = 1;
        }
        ciel_f2(window);
    }
}

void roman_collide_params(window_t *window)
{
    window->runner.forest.position.x -= 1000;
    window->runner.forest.position2.x -= 1000;
    window->runner.ciel.position.x -= 1000;
    window->runner.ciel.position2.x -= 1000;
    window->menu.sanglier_pos.x += 1000;
    window->runner.forest.vitesse = 20;
    window->runner.forest.position_r.x += 2000;
    window->menu.score -= 1000;
}

int roman_collide(window_t *window, int check)
{
    if (window->obelix.position.x + window->obelix.rect.width >=
    window->runner.forest.position_r.x &&
    window->obelix.position.x + window->obelix.rect.width <=
    window->runner.forest.position_r.x + 135
    && window->obelix.position.y + window->obelix.rect.height >
    window->runner.forest.position_r.y)
    {
        window->obelix.nblife--;
        if (window->obelix.nblife == 0) {
            check = end_runner(window);
        }
        else if (window->obelix.nblife != 0) {
            roman_collide_params(window);
        }
    }
    return (check);
}
