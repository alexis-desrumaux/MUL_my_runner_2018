/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_part10.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *delete_symbol(char *strarg, char *str)
{
    int i = 0;
    char *strarg2 = malloc(my_strlen(strarg) + 50);

    strarg2 = my_strcpy(strarg2, strarg);
    while (strarg2[i] != '\0') {
        if (strarg2[i] == '#') {
            strarg2[i] = 32;
        }
        i++;
    }
    str = my_strcpy(str, strarg2);
    return (str);

}

void win_display(window_t *window)
{
    int check = 0;
    int i = 0;
    char *str = malloc(500);

    sfMusic_stop(window->runner.music);
    window->menu.music_w = sfMusic_createFromFile("win.ogg");
    sfMusic_play(window->menu.music_w);
    window->menu.win = image2sprite("./image/win.png");
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_drawSprite(window->window, window->menu.win, NULL);
        sfRenderWindow_display(window->window);
        while (sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (window->event.type == sfEvtClosed)
                sfRenderWindow_close(window->window);
        }
        i++;
    }
}

int game_over_event(window_t *window, int check, int check_c)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            check = 1;
        }
        if (window->event.type == sfEvtKeyPressed && check_c == 1) {
            check = 2;
        }
    }
    return (check);
}
