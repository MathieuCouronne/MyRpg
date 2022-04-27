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

void handle_menu_events(menu_buttons_t *buttons, sfEvent event, game_t *game)
{
    if (event.type == sfEvtMouseButtonPressed)
        if (click_play_menu(buttons->play, event) == true) {
            game->scenes->current = MAIN_GAME;
        }
        if (click_play_menu(buttons->settings, event) == true) {
            // TODO add function
        }
        if (click_play_menu(buttons->quit, event) == true) {
            sfRenderWindow_close(game->window);
        }
}
