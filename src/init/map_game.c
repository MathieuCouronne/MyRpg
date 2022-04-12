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

game_asset_t *init_map(game_t *game)
{
    game_asset_t *map = malloc(sizeof(game_asset_t));

    if (!map)
        return NULL;
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile
            ("./assets/images/map.png", NULL);
    sfSprite_setScale(map->sprite, (sfVector2f) {1.3, 1.3});
    sfView_setCenter(game->view, (sfVector2f) {2290, 2300});
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    return map;
}

main_game_t *init_main_game(game_t *game)
{
    main_game_t *main_game = malloc(sizeof(main_game_t));

    if (!game)
        return NULL;
    main_game->map = init_map(game);
    return main_game;
}
