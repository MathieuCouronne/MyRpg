/*
** EPITECH PROJECT, 2021
** thread.c
** File description:
** Loading thread initializer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

static scenes_t *init_scenes(game_t *game)
{
    scenes_t *scenes = malloc(sizeof(scenes_t));

    scenes->current = MAIN_MENU;
    scenes->main_menu = init_main_menu();
    scenes->game_scene = init_main_game(game);
    scenes->fight = init_fight();
    scenes->settings = init_settings();
    scenes->saves = init_saves(game);
    scenes->pause = init_pause(game);
    scenes->creation_menu = init_creation();
    scenes->inventory = init_inventory();
    if (!scenes->main_menu || !scenes->game_scene || !scenes->fight ||
        !scenes->settings || !scenes->saves || !scenes->pause ||
        !scenes->creation_menu || !scenes->inventory)
        return NULL;
    return scenes;
}

static character_t **init_character_saves(void)
{
    character_t **saves = malloc(sizeof(character_t *) * 4);

    if (!saves)
        return NULL;
    saves[0] = get_character_save(PLAYER1_FILE_PATH);
    saves[1] = get_character_save(PLAYER2_FILE_PATH);
    saves[2] = get_character_save(PLAYER3_FILE_PATH);
    saves[3] = NULL;
    return saves;
}

static bool are_params_invalid(thread_params_t *params)
{
    return (!params->game->view || !params->game->sounds ||
        !params->game->collisions || !params->game->saves ||
        !params->game->characters || !params->game->stats ||
        !params->game->player
    );
}

static void init_params(thread_params_t *params)
{
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    params->game->player = init_player();
    params->game->config->assets_loaded = true;
    params->game->view = sfView_createFromRect(view_rect);
    params->game->sounds = menu_music(params->game->config);
    params->game->collisions = sfImage_createFromFile(AREAS_PATH);
    params->game->saves = init_character_saves();
    params->game->scenes = init_scenes(params->game);
    params->game->characters = init_characters();
    params->game->stats = init_war_stats();
}

bool load_game(thread_params_t *params)
{
    if (!params || !params->game || !params->loaded)
        return false;
    *(params->loaded) = 0;g
    params->game->config = parse_config();
    if (!params->game->config || (params->game->config->assets_loaded != 1 &&
    !download_assets(params->loaded)))
        return false;
    init_params(params);
    if (are_params_invalid(params))
        return false;
    *params->loaded = -1;
    return true;
}
