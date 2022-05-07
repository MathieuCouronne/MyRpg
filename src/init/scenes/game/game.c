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
    if (!map->sprite || !map->texture)
        return NULL;
    sfView_setCenter(game->view, (sfVector2f) {2270, 2030});
    sfView_zoom(game->view, 1.f / MAP_SCALE);
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
    main_game->npc = malloc(sizeof(npc_t) * 3);
    if (!main_game->npc)
        return NULL;
    main_game->npc[0] = init_albert();
    main_game->npc[1] = init_chief();
    main_game->npc[2] = NULL;
    if (!main_game->map || !main_game->chest || !main_game->npc[0] ||
    !main_game->npc[1])
        return NULL;
    return main_game;
}
