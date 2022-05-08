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

static void draw_items(character_t *character,
    size_t i, game_t *game, sfVector2f pos)
{
    for (size_t y = 0; y != character->inventory->width; y++) {
        if (character->inventory->content[i][y]->id != -1) {
            sfSprite_setPosition(game->scenes->inventory->loot
            [character->inventory->content[i][y]->id]->sprite, pos);
            sfRenderWindow_drawSprite(game->window, game->scenes->inventory->
            loot[character->inventory->content[i][y]->id]->sprite, NULL);
        }
    }
}

bool display_inventory(game_t *game)
{
    sfRenderWindow *window = NULL;
    inventory_sprite_t *inventory = NULL;
    character_t *character = game->saves[game->current];
    sfVector2f pos = {705, 380};

    if (!game || !game->window || !game->scenes || !game->scenes->inventory)
        return false;
    window = game->window;
    inventory = game->scenes->inventory;
    event_handling(game);
    sfRenderWindow_drawSprite(window, inventory->background->sprite, NULL);
    for (size_t i = 0; i != character->inventory->height; i++) {
        draw_items(character, i, game, pos);
        pos.x += 63;
    }
    return true;
}
