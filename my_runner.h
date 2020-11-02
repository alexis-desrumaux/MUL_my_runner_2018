/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

void create_elements_runner(window_t *window);
void create_elements_runner3(window_t *window);
sfSprite* image2sprite(char *path);
sfVector2f set_position_csfml(int x, int y);
void draw_elements_runner(window_t *window);
int gameplay_event_runner(window_t *window, int check);
void parralax_runner(window_t *window);
int runner_gameplay_part2(window_t *window, int check,
int check2, char *strarg);
int runner_gameplay(window_t *window, int check);
void middle_f(window_t *window);
void ciel_f2(window_t *window);
void ciel_f(window_t *window);
void roman_collide_params(window_t *window);
int roman_collide(window_t *window, int check);
int sanglier_anim(window_t *window, int check3);
int sanglier_run(window_t *window, int check);
void forest_f2(window_t *window);
void forest_f(window_t *window);
void middle_f2(window_t *window);
int manage_event_runner(int check, window_t *window, int check2);
int intro_obelix_runner_part2(window_t *window, int check2);
int intro_obelix_runner(window_t *window, int check, int check2);
char *board_element(window_t *window, char *strarg);
int sanglier_anim_part2(window_t *window, int check3);
void surprised_obelix(window_t *window, int option);
void walking_obelix_part3(window_t *window);
void walking_obelix_part2(window_t *window);
int walking_obelix(window_t *window);
int manage_event_runner_part2(window_t *window);
int start_runner(window_t *window);
void surprised_obelix_part5(window_t *window);
void surprised_obelix_part4(window_t *window);
void surprised_obelix_part3(window_t *window);
void surprised_obelix_part2(window_t *window);
int printrandoms(int lower, int upper, int count);
void jump_timemanager(window_t *window);
int manage_jump(int check3, window_t *window);
void managetime_runner2(window_t *window);
void managetime_runner(window_t *window);
int manage_time_g_over_2(window_t *window, int check_c);
void manage_time_g_over(window_t *window);
void game_over_draw_f(window_t *window);
int game_over_display(window_t *window);
int end_runner(window_t *window);
char *delete_symbol(char *strarg, char *str);
void win_display(window_t *window);
int game_over_event(window_t *window, int check, int check_c);
sfText* string2text(char *font_path, char *str);
