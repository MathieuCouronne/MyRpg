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
    if (!(scenes->main_menu = init_main_menu()) ||
    !(scenes->game_scene = init_main_game(game)) ||
    !(scenes->fight = init_fight()) ||
    !(scenes->settings = init_settings(game)) ||
    !(scenes->saves = init_saves(game)) ||
    !(scenes->pause = init_pause(game)) ||
    !(scenes->creation_menu = init_creation()) ||
    !(scenes->inventory = init_inventory()))
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

static void init_params(thread_params_t *params)
{
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    params->game->player = init_player();
    params->game->enemy = create_enemies();
    params->game->config->assets_loaded = true;
    params->game->view = sfView_createFromRect(view_rect);
    params->game->sounds = menu_music(params->game->config);
    params->game->collisions = sfImage_createFromFile(AREAS_PATH);
    params->game->saves = init_character_saves();
    params->game->scenes = init_scenes(params->game);
    params->game->characters = init_characters();
    params->game->stats = init_war_stats();
    params->game->quests = init_quests();
    params->game->current = 0;
}

bool load_game(thread_params_t *params)
{
    if (!params || !params->game || !params->loaded)
        return false;
    *(params->loaded) = 0;
    params->game->config = parse_config();
    if (!params->game->config || !check_config(params->game->config)
    || (params->game->config->assets_loaded != 1 &&
    !download_assets(params->loaded))) {
        *params->loaded = -1;
        return false;
    }
    init_params(params);
    *params->loaded = -1;
    return true;
}
