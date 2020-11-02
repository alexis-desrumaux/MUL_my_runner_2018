/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** struct_def.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void create_elements_runner5(window_t *window)
{
    window->menu.score = 0;
    window->obelix.position = set_position_csfml(610, 500);
    window->runner.forest.clock_f = sfClock_create();
    window->runner.middle.clock_m = sfClock_create();
    window->runner.ciel.clock_b = sfClock_create();
    window->obelix.clock_s = sfClock_create();
}

void create_elements_runner4(window_t *window)
{
    window->runner.ciel.position.x = 0;
    window->runner.ciel.position2.x = 5760;
    window->runner.forest.position.x = 0;
    window->runner.forest.position2.x = 5760;
    window->runner.forest.position_r.x = 5760;
    window->runner.forest.position_r.y = 510;
    window->runner.middle.position.x = 0;
    window->runner.middle.position.y = 130;
    window->runner.middle.position2.x = 0;
    window->runner.middle.position2.y = 130;
    window->menu.sanglier_pos.x = 15000;
    window->menu.text_pos.x = 710;
    window->menu.text_pos.y = 65;
    window->runner.check = 1;
    window->runner.ciel.check = 1;
    window->runner.middle.check = 1;
    window->runner.forest.vitesse = 30;
    window->menu.text = string2text("./image/arial.ttf", "0");
    sfText_setPosition(window->menu.text, window->menu.text_pos);
    create_elements_runner5(window);
}

void create_elements_runner3(window_t *window)
{
    window->runner.pourcent = 100;
    window->obelix.nblife = 3;
    window->runner.music = sfMusic_createFromFile("runner.ogg");
    window->obelix.rect.left = 638;
    window->obelix.rect.width = 100;
    window->obelix.rect.top = 28;
    window->obelix.rect.height = 240;
    window->runner.forest.sprite = image2sprite("./image/parralax1.png");
    window->runner.forest.sprite2 = image2sprite("./image/parralax1.png");
    window->runner.forest.sprite_r = image2sprite("./image/romain_j.png");
    window->runner.middle.sprite = image2sprite("./image/athenes.png");
    window->runner.middle.sprite2 = image2sprite("./image/athenes.png");
    window->runner.ciel.sprite = image2sprite("./image/ciel.png");
    window->runner.ciel.sprite2 = image2sprite("./image/ciel.png");
    window->menu.gameover = image2sprite("./image/game_over.png");
    window->menu.board = image2sprite("./image/pancarte.png");
    window->menu.sanglier = image2sprite("./image/sanglier.png");
    create_elements_runner4(window);
}

void create_elements_runner2(window_t *window)
{
    window->obelix.sprite = image2sprite("obelix.png");
    window->sprite = image2sprite("./image/Asterix-et-obelix_lolol.png");
    window->title = image2sprite("./image/titre.png");
    window->menu.start = image2sprite("./image/start.png");
    window->menu.sanglier = image2sprite("./image/sanglier.png");
    window->menu.sanglier_r = image2sprite("./image/sanglier_r.png");
    window->obelix.position = set_position_csfml(0, 505);
    window->menu.sanglier_pos = set_position_csfml(1770, 600);
    window->title_pos = set_position_csfml(600, 100);
}

void create_elements_runner(window_t *window)
{
    sfRenderWindow_setFramerateLimit(window->window, 120);
    window->music = sfMusic_createFromFile("asterix.ogg");
    window->music2 = sfMusic_createFromFile("run.ogg");
    window->obelix.rect.left = 638;
    window->obelix.rect.width = 100;
    window->obelix.rect.top = 28;
    window->obelix.rect.height = 240;
    window->obelix.position_o = 1;
    window->obelix.position_so = 1;
    window->obelix.position_sco = 1;
    window->clock.clock = sfClock_create();
    window->clock.clock_anim = sfClock_create();
    create_elements_runner2(window);
}
