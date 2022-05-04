/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** Main menu navigation scenes
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void go_to_settings(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = SETTINGS;
}

void go_to_saves(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = SAVES;
}

void quit_game(game_t *game)
{
    sfRenderWindow_close(game->window);
}
