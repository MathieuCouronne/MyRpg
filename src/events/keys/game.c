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

    if (code != sfKeyEscape && code != game->config->keys->inventory)
        return false;
    if (code == sfKeyEscape)
        game->scenes->current = PAUSE;
    else if (game->event.key.code == game->config->keys->inventory)
        game->scenes->current = INVENTORY;
    sfRenderWindow_setView(game->window, view);
    game->scenes->prev = game->scenes->current;
    return true;
}

// open_chest(game);
void handle_game_change_scenes(game_t *game)
{
    if (game->event.type != sfEvtKeyPressed)
        return;
    if (!change_scenes(game))
        handle_quests_keys(game);
}
