/*
** EPITECH PROJECT, 2021
** chest.c
** File description:
** init_chest
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_inventory(game_t *game)
{
    game_asset_t *inventory = malloc(sizeof(game_asset_t));
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    inventory->sprite = sfSprite_create();
    inventory->texture = sfTexture_createFromFile(INVENTORY_PATH, NULL);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setScale(inventory->sprite, (sfVector2f) {1.1, 1.1});
    inventory->pos = sfRenderWindow_mapPixelToCoords(game->window, (sfVector2i) {0, 0}, game->view);
    sfSprite_setPosition(inventory->sprite, inventory->pos);
    return inventory;
}

void display_inventory(game_t *game)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window, (sfVector2i) {0, 0}, game->view);
    sfSprite_setPosition(game->inventory->sprite, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawSprite(game->window, game->inventory->sprite, NULL);
}
