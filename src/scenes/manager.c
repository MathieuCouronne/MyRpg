/*
** EPITECH PROJECT, 2022
** manager.c
** File description:
** Scene manager
*/

#include <stdbool.h>
#include "my_rpg.h"

// TODO: remove this function when we'll have the loading scene
static bool empty(game_t *game)
{
    (void) game;
    return true;
}

static bool (*scenes_list[])(game_t *game) = {
    empty, display_main_menu, display_main_game, display_fight, NULL
};

void scene_manager(game_t *game)
{
    for (unsigned short i = 0; scenes_list[i]; i++) {
        if (i != game->scenes->current)
            continue;
        scenes_list[i](game);
        break;
    }
}