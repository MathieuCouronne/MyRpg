/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"
#include "macros.h"

game_asset_t *init_map(game_t *game)
{
    game_asset_t *map = malloc(sizeof(game_asset_t));

    if (!map)
        return NULL;
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile(MAP_PATH, NULL);
    sfView_setCenter(game->view, (sfVector2f) {2270, 2030});
    sfView_zoom(game->view, .5f);
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    return map;
}

main_game_t *init_main_game(game_t *game)
{
    main_game_t *main_game = malloc(sizeof(main_game_t));

    if (!game)
        return NULL;
    main_game->map = init_map(game);
    main_game->chest = init_chest();
    main_game->albert = init_albert();
    main_game->chief = init_chief();
    return main_game;
}
