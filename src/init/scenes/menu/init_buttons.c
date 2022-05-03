/*
** EPITECH PROJECT, 2021
** init_menu_button.c
** File description:
** init menu button
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "structs.h"
#include "my_rpg.h"

void go_to_game(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_GAME;
}

void go_to_settings(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = SETTINGS;
}

void quit_game(game_t *game)
{
    sfRenderWindow_close(game->window);
}

void go_to_saves(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = SAVES;
}

button_t **init_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    float pos_x = 960 - 390 / 2;

    if (!buttons)
        return NULL;
    buttons[0] = create_button("Play", (sfVector2f) {pos_x, 500}, go_to_saves,
    (sfVector2f) {1, 1});
    buttons[1] = create_button("Settings",(sfVector2f) {pos_x, 650},
    go_to_settings, (sfVector2f) {1, 1});
    buttons[2] = create_button("Quit", (sfVector2f) {pos_x, 800}, quit_game,
    (sfVector2f) {1, 1});
    buttons[3] = NULL;
    return buttons;
}
