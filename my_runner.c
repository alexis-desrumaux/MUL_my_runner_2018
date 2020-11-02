/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void draw_title_intro(window_t *window)
{
    sfRenderWindow_drawSprite(window->window, window->title, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.start, NULL);
}

int intro(window_t *window)
{
    int check[4] = {0, 0, 0};

    while (sfRenderWindow_isOpen(window->window) && check[0] == 0) {
        managetime_runner(window);
        sfSprite_setPosition(window->obelix.sprite, window->obelix.position);
        sfSprite_setTextureRect(window->obelix.sprite, window->obelix.rect);
        sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
        check[2] = sanglier_anim(window, check[2]);
        if (check[1] == 3)
        draw_title_intro(window);
        if (window->clock.seconds_anim > 1.5)
        sfRenderWindow_drawSprite(window->window, window->obelix.sprite, NULL);
        sfRenderWindow_display(window->window);
        check[0] = manage_event_runner(check[0], window, check[1]);
        check[1] = intro_obelix_runner(window, check[0], check[1]);
        sfRenderWindow_clear(window->window, sfBlack);
    }
    return (check[0]);
}

void h_display(void)
{
    my_putstr("As Obelix, you must run after a boar.");
    my_putstr(" But beware of the Romans\n");
    my_putstr("who will block the road. Be vigilant and catch this boar!\n\n");
    my_putstr("Commands:\n");
    my_putstr("-SPACE: To jump over the Romans\n");
    my_putstr("-LEFTKEY: To run slower\n");
    my_putstr("-RIGHTKEY: To run faster\n\n");
    my_putstr("RULES:\n");
    my_putstr("You have 3 lives. Each life will cost you a");
    my_putstr(" 1000px rollback and a loss\n");
    my_putstr("of 1000points. If you do not run fast");
    my_putstr(" enough the wild boar will\n");
    my_putstr("eventually escape you. Beyond 3 lives, ");
    my_putstr("you have lost and will have to\n");
    my_putstr("start again at 0. Can you take up the challenge ?\n\n");
    my_putstr("MAP:\n");
    my_putstr("-map.txt\n\n");
    my_putstr("USAGE:\n./my_runner map.txt\n");
}

int error_handling(int argc, char **argv)
{
    int check = 0;

    if (argc != 2)
    check = 84;
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
        h_display();
        if (argv[1][0] != '-')
        check = 1;
    }
    return (check);
}

int main(int argc, char **argv)
{
    int check = 0;
    int error_check = 0;
    window_t *window = malloc(sizeof(window_t));
    sfVideoMode mode = {1920, 1080, 32};

    error_check = error_handling(argc, argv);
    if (error_check == 1) {
        window->menu.x = 0.65;
        window->window = sfRenderWindow_create(mode, "My_runner",
        sfResize | sfClose, NULL);
        create_elements_runner(window);
        sfMusic_play(window->music);
        check = intro(window);
        if (check == 2) {
            sfRenderWindow_clear(window->window, sfBlack);
            runner_gameplay(window, check);
        }
    }
    else if (error_check == 84)
    return (84);
}
