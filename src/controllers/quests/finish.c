/*
** EPITECH PROJECT, 2021
** finish.c
** File description:
** Finish quests
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

void finish_quest(game_t *game)
{
    quest_t *current = game->quests->quests[game->quests->current];
    inventory_t *inventory = game->saves[game->current]->inventory;
    slot_t *item = NULL;

    for (unsigned int i = 0; current->required[i]; i++) {
        item = current->required[i];
        remove_from_inventory(inventory, item->id, item->quantity);
    }
    for (unsigned int i = 0; current->rewards && current->rewards[i]; i++) {
        item = current->rewards[i];
        remove_from_inventory(inventory, item->id, item->quantity);
    }
    add_experience(game->saves[game->current], current->xp);
    current->done = true;
    game->quests->current++;
    if (game->quests->current == 3) {
        sfRenderWindow_setView(game->window,
            sfRenderWindow_getDefaultView(game->window));
        game->scenes->current = CREDITS;
    }
}
