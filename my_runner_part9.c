/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part9.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int manage_time_g_over_2(window_t *window, int check_c)
{
    if (window->clock.seconds_over > 0 && window->clock.seconds_over < 1.25) {
        sfRenderWindow_drawSprite(window->window, window->menu.gameover, NULL);
    }
    else if (window->clock.seconds_over > 2.5) {
        sfClock_restart(window->clock.clock_over);
    }
    if (window->clock.seconds_over > 0.25)
    check_c = 1;
    return (check_c);
}

void manage_time_g_over(window_t *window)
{
    window->clock.time_over = sfClock_getElapsedTime(window->clock.clock_over);
    window->clock.seconds_over =
    window->clock.time_over.microseconds / 1000000.0;
}

void game_over_draw_f(window_t *window)
{
    sfRenderWindow_drawSprite(window->window, window->runner.ciel.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->runner.ciel.sprite2, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->runner.middle.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->runner.middle.sprite2, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->runner.forest.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->runner.forest.sprite2, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->runner.forest.sprite_r, NULL);
}

int game_over_display(window_t *window)
{
    int check = 0;
    int check_c = 0;
    sfMusic_stop(window->runner.music);
    window->clock.clock_over = sfClock_create();

    while (check == 0)
    {
        manage_time_g_over(window);
        game_over_draw_f(window);
        check_c = manage_time_g_over_2(window, check_c);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        check = game_over_event(window, check, check_c);
    }
    return (check);
}

int end_runner(window_t *window)
{
    return (3);
}
