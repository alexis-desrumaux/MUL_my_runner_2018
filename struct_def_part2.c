/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** struct_def_part2.c
*/

#include "mylib.h"
#include "my_runner.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

sfVector2f set_position_csfml(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return (position);
}

sfText* string2text(char *font_path, char *str)
{
    sfText* text;
    sfFont* font;

    font = sfFont_createFromFile(font_path);
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, str);
    return (text);
}

sfSprite* image2sprite(char *path)
{
    sfSprite* sprite;
    sfTexture* texture;

    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
