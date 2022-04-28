/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game events handling
*/

#include "my_rpg.h"

static const event_controller_t EVENT_TYPES[] = {
    // {sfEvtKeyPressed, &handle_arrow_keys},
    {sfEvtMouseWheelScrolled, &handle_mouse_wheel},
    {0, NULL}
};

void handle_events(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    for (unsigned short i = 0; EVENT_TYPES[i].fn; i++) {
        if (EVENT_TYPES[i].type == event->type)
            EVENT_TYPES[i].fn(game, event);
    }
}

void handle_buttons_clicks(game_t *game, button_t **buttons)
{
    for (unsigned short i = 0; buttons[i]; i++) {
        if (is_button_clicked(game, buttons[i]))
            buttons[i]->on_click(game);
    }
}
