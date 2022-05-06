/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game event handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static bool change_scenes(game_t *game)
{
    sfKeyCode code = game->event.key.code;
    const sfView *view = sfRenderWindow_getDefaultView(game->window);

    if (code != sfKeyEscape && code != sfKeyI)
        return false;
    if (code == sfKeyEscape)
        game->scenes->current = PAUSE;
    else if (game->event.key.code == sfKeyI)
        game->scenes->current = INVENTORY;
    sfRenderWindow_setView(game->window, view);
    game->scenes->prev = game->scenes->current;
    return true;
}

void handle_game_change_scenes(game_t *game)
{
    if (game->event.type != sfEvtKeyPressed)
        return;
    if (!change_scenes(game) && game->event.key.code == sfKeyE)
        open_chest(game);
}
