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

// sfRectangleShape *rect_inventory(void)
// {
//     sfRectangleShape *rect = malloc(sizeof(sfRectangleShape *));
//     return rect;
// }

game_asset_t *init_inventory(game_t *game)
{
    game_asset_t *inventory = malloc(sizeof(game_asset_t));
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    inventory->sprite = sfSprite_create();
    //inventory->rect = rect_inventory();
    inventory->texture = sfTexture_createFromFile(INVENTORY_PATH, NULL);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setScale(inventory->sprite, (sfVector2f) {1.1, 1.1});
    inventory->pos = sfRenderWindow_mapPixelToCoords(game->window, (sfVector2i) {0, 0}, game->view);
    sfSprite_setPosition(inventory->sprite, inventory->pos);
    return inventory;
}
