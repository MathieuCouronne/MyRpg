/*
** EPITECH PROJECT, 2021
** inventory.c
** File description:
** Display inventory
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include "macros.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->inventory->buttons);
        if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == game->config->keys->inventory) {
            game->scenes->prev = game->scenes->current;
            game->scenes->current = MAIN_GAME;
        }
    }
}

bool display_inventory(game_t *game)
{
    sfRenderWindow *window = NULL;
    inventory_sprite_t *inventory = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->inventory)
        return false;
    window = game->window;
    inventory = game->scenes->inventory;
    event_handling(game);
    sfRenderWindow_drawSprite(window, inventory->background->sprite, NULL);
    init_inventory_sprite(BOOK_PATH);
    sfRenderWindow_drawSprite(window, inventory->loot[0]->sprite, NULL);
    return true;
}
