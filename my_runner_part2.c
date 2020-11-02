/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** my_runner_part2.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void draw_elements_runner(window_t *window)
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
    sfRenderWindow_drawSprite(window->window, window->menu.sanglier_r, NULL);
    sfRenderWindow_drawSprite(window->window, window->obelix.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.board, NULL);
    sfRenderWindow_drawText(window->window, window->menu.text, NULL);
}

int gameplay_event_runner(window_t *window, int check)
{
    check = manage_event_runner(check, window, 4);
    check = roman_collide(window, check);
    check = sanglier_run(window, check);
    return (check);
}

void parralax_runner(window_t *window)
{
    ciel_f(window);
    middle_f(window);
    forest_f(window);
    sfSprite_setPosition(window->obelix.sprite, window->obelix.position);
}

int runner_gameplay_part2(window_t *window, int check, int check2, char *strarg)
{
    while (check == 2 && sfRenderWindow_isOpen(window->window)) {
        managetime_runner2(window);
        sfMusic_setLoop(window->runner.music, sfTrue);
        if (window->clock.seconds_anim > 0.75) {
            parralax_runner(window);
            if (window->clock.seconds > 0.02) {
                surprised_obelix(window, 2);
                sfClock_restart(window->clock.clock);
            }
            sfSprite_setTextureRect(window->obelix.sprite, window->obelix.rect);
            strarg = board_element(window, strarg);
            draw_elements_runner(window);
            check = gameplay_event_runner(window, check);
            check2 = manage_jump(check2, window);
            sfRenderWindow_display(window->window);
            sfRenderWindow_clear(window->window, sfBlack);
        }
    }
    return (check);
}

int runner_gameplay(window_t *window, int check)
{
    int check2 = 0;
    char *strarg = malloc(500);

    strarg = "score:#0#   boar:#0#    life:#0#";
    sfMusic_stop(window->music);
    create_elements_runner3(window);
    sfMusic_play(window->runner.music);
    window->obelix.position_sco = 1;
    sfClock_restart(window->clock.clock);
    sfClock_restart(window->clock.clock_anim);
    window->obelix.isspace = 0;
    check = runner_gameplay_part2(window, check, check2, strarg);
    if (check != 1 && check != 4 && sfRenderWindow_isOpen(window->window)) {
        if (game_over_display(window) == 2)
        runner_gameplay(window, 2);
    }
    if (check == 4)
    win_display(window);
}
