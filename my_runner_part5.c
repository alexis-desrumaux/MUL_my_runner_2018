/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part5.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int manage_event_runner(int check, window_t *window, int check2)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
        }
        if (window->event.type == sfEvtMouseButtonPressed && check2 == 3) {
                check = start_runner(window);
        }
        if (window->event.type == sfEvtKeyPressed && check2 == 4) {
            if (window->event.key.code == sfKeySpace) {
                window->obelix.isspace = 1;
            }
        }
        manage_event_runner_part2(window);
    }
    return (check);
}

int intro_obelix_runner_part2(window_t *window, int check2)
{
    if (window->clock.seconds_anim > 16 &&
    window->clock.seconds_anim < 19 && window->clock.seconds > 0.001) {
        if (check2 == 1) {
            sfClock_restart(window->clock.clock);
        }
        check2 = 2;
        surprised_obelix(window, 2);
        if (window->clock.seconds_anim > 17)
        window->obelix.position.x += 15;
        sfClock_restart(window->clock.clock);
    }
    if (window->clock.seconds_anim > 19 && window->clock.seconds_anim < 20)
    check2 = 3;
    return (check2);
}

int intro_obelix_runner(window_t *window, int check, int check2)
{
    if (window->clock.seconds > 0.35 &&
    window->clock.seconds_anim > 2 && window->clock.seconds_anim < 10) {
        walking_obelix(window);
        window->obelix.position.x += 30;
        sfClock_restart(window->clock.clock);
    }
    if (window->clock.seconds_anim > 10 &&
    window->obelix.position_so != 5 && window->clock.seconds > window->menu.x) {
        surprised_obelix(window, 1);
        sfClock_restart(window->clock.clock);
        window->menu.x = 1.5;
        if (check2 == 0 && window->clock.seconds_anim > 14.67) {
            sfMusic_play(window->music2);
            check2 = 1;
        }
    }
    check2 = intro_obelix_runner_part2(window, check2);
    return (check2);
}

char *board_element(window_t *window, char *strarg)
{
    char *str;

    strarg = replace_strarg_int(strarg, 2, window->menu.score);
    strarg = replace_strarg_int(strarg, 4, window->menu.sanglier_pos.x);
    strarg = replace_strarg_int(strarg, 6, window->obelix.nblife);
    str = malloc(my_strlen(strarg));
    str = delete_symbol(strarg, str);
    sfText_setString(window->menu.text, str);
    return (strarg);
}

int sanglier_anim_part2(window_t *window, int check3)
{
    if (window->clock.seconds_anim > 15) {
        if (check3 == 0) {
            check3 = 1;
        }
        sfSprite_setPosition(window->menu.sanglier_r,
        window->menu.sanglier_pos);
        sfRenderWindow_drawSprite(window->window,
        window->menu.sanglier_r, NULL);
        window->menu.sanglier_pos.x += 10;
    }
    return (check3);
}
