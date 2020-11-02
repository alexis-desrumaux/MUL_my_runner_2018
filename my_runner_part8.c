/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part8.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int printrandoms(int lower, int upper, int count)
{
    int i;
    int num;

    for (i = 0; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;
    }
    return (num);
}

void jump_timemanager(window_t *window)
{
    window->obelix.time_s = sfClock_getElapsedTime(window->obelix.clock_s);
    window->obelix.seconds_s = window->obelix.time_s.microseconds / 1000000.0;
}

int manage_jump(int check3, window_t *window)
{
    if (window->obelix.isspace == 1) {
        if (check3 == 0) {
            sfClock_restart(window->obelix.clock_s);
            check3 = 1;
        }
        jump_timemanager(window);
        if (window->obelix.seconds_s < 0.1) {
            window->obelix.position.y -= 18;
        }
        if (window->obelix.seconds_s > 0.4 && window->obelix.seconds_s < 0.5) {
            window->obelix.position.y += 18;
        }
        if (window->obelix.seconds_s > 0.5) {
            window->obelix.isspace = 0;
            check3 = 0;
        }
    }
    return (check3);
}

void managetime_runner2(window_t *window)
{
    window->runner.forest.time_f =
    sfClock_getElapsedTime(window->runner.forest.clock_f);
    window->runner.forest.seconds_f =
    window->runner.forest.time_f.microseconds / 1000000.0;
    window->runner.middle.time_m =
    sfClock_getElapsedTime(window->runner.middle.clock_m);
    window->runner.middle.seconds_m =
    window->runner.middle.time_m.microseconds / 1000000.0;
    window->runner.ciel.time_b =
    sfClock_getElapsedTime(window->runner.ciel.clock_b);
    window->runner.ciel.seconds_b =
    window->runner.ciel.time_b.microseconds / 1000000.0;
    window->clock.time =
    sfClock_getElapsedTime(window->clock.clock);
    window->clock.seconds =
    window->clock.time.microseconds / 1000000.0;
    window->clock.time_anim =
    sfClock_getElapsedTime(window->clock.clock_anim);
    window->clock.seconds_anim =
    window->clock.time_anim.microseconds / 1000000.0;
}

void managetime_runner(window_t *window)
{
    window->clock.time = sfClock_getElapsedTime(window->clock.clock);
    window->clock.seconds = window->clock.time.microseconds / 1000000.0;
    window->clock.time_anim = sfClock_getElapsedTime(window->clock.clock_anim);
    window->clock.seconds_anim =
    window->clock.time_anim.microseconds / 1000000.0;
}
