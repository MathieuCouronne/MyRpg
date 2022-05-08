/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game event handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void change_current(game_t *game)
{
    if (game->event.key.code == game->config->keys->pause) {
        game->scenes->current = PAUSE;
        return;
    }
    if (game->event.key.code == game->config->keys->inventory) {
        game->scenes->current = INVENTORY;
        return;
    }
    if (game->event.key.code == sfKeyT) {
        game->scenes->current = STATS;
        return;
    }
}

static bool change_scenes(game_t *game)
{
    sfKeyCode code = game->event.key.code;
    const sfView *view = sfRenderWindow_getDefaultView(game->window);

    if (code != game->config->keys->pause &&
    code != game->config->keys->inventory && code != sfKeyT)
        return false;
    change_current(game);
    sfRenderWindow_setView(game->window, view);
    game->scenes->prev = game->scenes->current;
    return true;
}

void handle_game_change_scenes(game_t *game)
{
    if (game->event.type != sfEvtKeyPressed)
        return;
    if (!change_scenes(game))
        handle_quests_keys(game);
}
