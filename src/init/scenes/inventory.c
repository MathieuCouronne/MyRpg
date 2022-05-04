/*
** EPITECH PROJECT, 2021
** chest.c
** File description:
** init_chest
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

// TODO: set position of the sprite on opening instead of in initializing
game_asset_t *init_inventory(game_t *game)
{
    game_asset_t *inventory = malloc(sizeof(game_asset_t));

    inventory->sprite = sfSprite_create();
    inventory->texture = sfTexture_createFromFile(INVENTORY_PATH, NULL);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setScale(inventory->sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setPosition(inventory->sprite, inventory->pos);
    return inventory;
}

void display_inventory(game_t *game)
{
    sfVector2i top_left = {0, 0};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window, top_left,
        game->view);

    sfSprite_setPosition(game->inventory->sprite, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawSprite(game->window, game->inventory->sprite, NULL);
}
