/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part4.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int sanglier_anim(window_t *window, int check3)
{
    if (window->clock.seconds_anim > 10 && window->clock.seconds_anim < 17) {
        if (window->clock.seconds_anim < 14) {
            window->menu.sanglier_pos.x -= 0.1;
            sfSprite_setPosition(window->menu.sanglier,
            window->menu.sanglier_pos);
            sfRenderWindow_drawSprite(window->window,
            window->menu.sanglier, NULL);
        }
        if (window->clock.seconds_anim > 14 && window->clock.seconds_anim < 15)
        sfRenderWindow_drawSprite(window->window, window->menu.sanglier, NULL);
        check3 = sanglier_anim_part2(window, check3);
    }
    return (check3);
}

int sanglier_run(window_t *window, int check)
{
    if (window->obelix.position.x + window->obelix.rect.width >=
    window->menu.sanglier_pos.x &&
    window->obelix.position.x + window->obelix.rect.width <=
    window->menu.sanglier_pos.x + 200
    && window->obelix.position.y + window->obelix.rect.height >
    window->menu.sanglier_pos.y)
    check = 4;
    window->menu.sanglier_pos.x -= window->runner.forest.vitesse - 29;
    sfSprite_setPosition(window->menu.sanglier_r, window->menu.sanglier_pos);
    return (check);
}

void forest_f2(window_t *window)
{
    window->runner.forest.position.x -= window->runner.forest.vitesse;
    window->runner.forest.position2.x -= window->runner.forest.vitesse;
    window->runner.forest.position_r.x -= window->runner.forest.vitesse;
    window->menu.score += window->runner.forest.vitesse;
    if (window->runner.forest.position_r.x < window->obelix.position.x - 1000) {
        window->runner.forest.position_r.x += printrandoms(1920, 5000, 1);
    }
    sfSprite_setPosition(window->runner.forest.sprite,
    window->runner.forest.position);
    sfSprite_setPosition(window->runner.forest.sprite2,
    window->runner.forest.position2);
    sfSprite_setPosition(window->runner.forest.sprite_r,
    window->runner.forest.position_r);
    sfClock_restart(window->runner.forest.clock_f);
}

void forest_f(window_t *window)
{
    if (window->runner.forest.seconds_f > 0.01) {
        if (window->runner.forest.position2.x < window->obelix.position.x - 1000
        && window->runner.check == 1) {
            window->runner.forest.position.x += 11520;
            window->runner.check = 2;
        }
        if (window->runner.forest.position.x < window->obelix.position.x - 1000
        && window->runner.check == 2) {
            window->runner.forest.position2.x += 11520;
            window->runner.check = 1;
        }
        forest_f2(window);
    }
}

void middle_f2(window_t *window)
{
    window->runner.middle.position.x -= 5;
    window->runner.middle.position2.x -= 5;
    sfSprite_setPosition(window->runner.middle.sprite,
    window->runner.middle.position);
    sfSprite_setPosition(window->runner.middle.sprite2,
    window->runner.middle.position2);
    window->runner.forest.position_r.x -= 5;
    sfClock_restart(window->runner.middle.clock_m);
}
