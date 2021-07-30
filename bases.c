/*
** EPITECH PROJECT, 2020
** base
** File description:
** .
*/

#include "include/hunter.h"

int main(int argc, char **argv)
{
    if (helper_error(argc, argv) == 84)
        return 84;
    if (helper_error(argc, argv) == 1)
        return 0;
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};
    sfEvent event;
    sfIntRect rect;
    sfSprite *my_sprite = sfSprite_create();
    sfTexture *my_texture = sfTexture_createFromFile("../../Pictures/hunter/my_hunter_spritesheet.png", NULL);
    sfTexture *my_background = sfTexture_createFromFile("../../Pictures/hunter/background.png", NULL);
    sfSprite *my_sprite_background = sfSprite_create();
    sfVector2f my_pos = {0, 40};
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    sfSprite_setTexture(my_sprite_background, my_background, sfFalse);
    sfSprite_setPosition(my_sprite, my_pos);

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;

    sfSprite_setTextureRect(my_sprite, rect);

    window = sfRenderWindow_create(video_mode,
                                   "boostrap hunter", sfClose | sfResize, NULL);

    sfRenderWindow_setFramerateLimit(window, 15);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, &my_pos);
        }
        move_rect(&rect, 110, 220);
        move_bird(&my_pos, 800, 600);
        sfSprite_setPosition(my_sprite, my_pos);
        sfSprite_setTextureRect(my_sprite, rect);
        sfRenderWindow_drawSprite(window, my_sprite_background, NULL);
        sfRenderWindow_drawSprite(window, my_sprite, NULL);
    }
    return 0;
}

int helper_error(int argc, char **argv)
{
    if (argc ==  2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("\nThe goal of the game is to shoot on the birds.\n");
        my_putstr("For this you just have to left-click on them.\n\n");
        return(1);
    }
    else if (argc > 1)
        return(84);
    else
        return 0;
}

void move_bird(sfVector2f *my_pos, int max_x, int max_y)
{
    my_pos->x += 20;
    if (my_pos->x >= max_x) {
        my_pos->x = -110;
        my_pos->y = ((rand()%465) + 50);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f *my_pos)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event, my_pos);
}

void manage_mouse_click(sfEvent event, sfVector2f *my_pos)
{
    float xb = my_pos->x;
    float yb = my_pos->y;

    int mx = event.mouseButton.x;
    int	my = event.mouseButton.y;
    if (xb < mx && mx < (xb+100) && (yb < my && my < (yb + 100))) {
        my_pos->x = -110;
        my_pos->y = ((rand()%465)+50);
    }
}
