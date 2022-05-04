/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->pause->buttons);
    }
}

bool display_creation(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_creation_scenes_t *creation = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->creation_menu)
        return false;
    window = game->window;
    creation = game->scenes->creation_menu ;
    //buttons = creation->buttons;
    event_handling(game);
    sfRenderWindow_drawSprite(window, creation->background->sprite, NULL);
    return true;
}
