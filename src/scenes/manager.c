/*
** EPITECH PROJECT, 2022
** manager.c
** File description:
** Scene manager
*/

#include <stdbool.h>
#include "my_rpg.h"

static bool (*scenes_list[])(game_t *game) = {
    display_main_menu, display_main_game, display_fight,
    display_creation, display_settings, display_saves, display_pause,
    display_inventory, NULL
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
