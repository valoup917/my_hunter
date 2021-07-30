/*
** EPITECH PROJECT, 2020
** .h
** File description:
** .
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

void my_putchar(char c);
int my_putstr(char const *str);

void analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f *my_pos);
void manage_mouse_click(sfEvent event, sfVector2f *my_pos);
void close_window(sfRenderWindow *window);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_bird(sfVector2f *my_pos, int max_x, int max_y);
int helper_error(int argc, char **argv);
