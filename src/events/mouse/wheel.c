/*
** EPITECH PROJECT, 2021
** wheel.c
** File description:
** Game wheel events handling
*/

#include "my_rpg.h"

void handle_mouse_wheel(game_t *game, sfEvent *event)
{
    if (event->type != sfEvtMouseWheelScrolled)
        return;
    if (event->mouseWheelScroll.delta == 1 && game->view) {
        sfView_zoom(game->view, 0.95f);
    } else if (event->mouseWheelScroll.delta == -1 && game->view) {
        sfView_zoom(game->view, 1.05f);
    }
}
