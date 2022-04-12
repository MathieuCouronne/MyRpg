/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include "game.h"
#include <stdlib.h>

game_asset_t *init_map(void)
{
    game_asset_t *map = malloc(sizeof(game_asset_t));

    if (!map)
        return NULL;
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile
            ("./assets/images/map.png", NULL);
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    return map;
}

main_game_t *init_main_game(void)
{
    main_game_t *game = malloc(sizeof(main_game_t));

    if (!game)
        return NULL;
    game->map = init_map();
    return game;
}
