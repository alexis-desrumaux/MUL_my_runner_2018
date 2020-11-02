/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** struct.h
*/

#define STRUCT_H_
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct background_s
{
    sfSprite* sprite;
    sfSprite* sprite2;
    sfVector2f position;
    sfVector2f position2;
    sfIntRect rect;
    sfTime time_b;
    sfClock* clock_b;
    float seconds_b;
    int check;
} background_t;

typedef struct middleground_s
{
    sfSprite* sprite;
    sfSprite* sprite2;
    sfVector2f position;
    sfVector2f position2;
    sfIntRect rect;
    sfTime time_m;
    sfClock* clock_m;
    float seconds_m;
    int check;
} middleground_t;

typedef struct foreground_s
{
    sfSprite* sprite;
    sfSprite* sprite2;
    sfSprite* sprite_r;
    sfVector2f position;
    sfVector2f position2;
    sfVector2f position_r;
    sfIntRect rect;
    sfTime time_f;
    sfClock* clock_f;
    float seconds_f;
    int vitesse;
} foreground_t;

typedef struct running_ob_s
{
    background_t ciel;
    middleground_t middle;
    foreground_t forest;
    sfMusic* music;
    int check;
    int pourcent;
    int pourcent2;
} running_ob_t;

typedef struct menu_s
{
    sfSprite* start;
    sfSprite* gameover;
    sfSprite* win;
    sfSprite* board;
    sfMusic* music_w;
    sfVector2f start_pos;
    float x;
    sfText* text;
    int score;
    sfVector2f text_pos;
    sfSprite* sanglier;
    sfSprite* sanglier_r;
    sfVector2f sanglier_pos;
} menu_t;

typedef struct clock_s
{
    sfTime time;
    sfClock* clock;
    float seconds;
    sfTime time_anim;
    sfClock* clock_anim;
    float seconds_anim;
    sfTime time_over;
    sfClock* clock_over;
    float seconds_over;


} clock_ty;

typedef struct obelix_s
{
    sfTexture* texture;
    sfSprite* sprite;
    sfIntRect rect;
    sfVector2f position;
    sfTime time_s;
    sfClock* clock_s;
    float seconds_s;
    int isspace;
    int position_o;
    int position_so;
    int position_sco;
    int nblife;
} obelix_t;

typedef struct runner_s
{
    sfRenderWindow* window;
    sfEvent event;
    sfMusic* music;
    sfMusic* music2;
    sfSprite* sprite;
    sfSprite* title;
    sfVector2f title_pos;
    sfIntRect title_rect;
    clock_ty clock;
    obelix_t obelix;
    menu_t menu;
    running_ob_t runner;
} window_t;
