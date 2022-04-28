/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include <stdlib.h>

static void event_handling(game_t *game)
{
    handle_arrow_keys(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {

    }
}

bool display_main_game(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_game_t *main_game = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->main_menu ||
        !game->scenes->main_menu->buttons)
        return false;
    event_handling(game);
    window = game->window;
    main_game = game->scenes->game_scene;
    sfRenderWindow_setView(window, game->view);
    sfRenderWindow_drawSprite(window, main_game->map->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->chest->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprite, NULL);
    return true;
}
