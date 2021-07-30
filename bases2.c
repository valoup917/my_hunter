/*
** EPITECH PROJECT, 2020
** bases2
** File description:
** .
*/

#include "include/hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left > max_value) {
        rect->left = 0;
    }
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
