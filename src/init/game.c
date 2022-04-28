/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

static sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS};
    sfRenderWindow *window = sfRenderWindow_create(mode, WINDOW_NAME,
    sfFullscreen, NULL);

    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

scenes_t *init_scenes(game_t *game)
{
    scenes_t *scenes = malloc(sizeof(scenes_t));

    scenes->current = MAIN_MENU;
    scenes->main_menu = init_main_menu();
    scenes->game_scene = init_main_game(game);
    scenes->fight = init_fight();
    return scenes;
}

sfImage *init_collision_img(void)
{
    sfImage *image = sfImage_createFromFile(AREAS_PATH);

    if (!image)
        return NULL;
    return image;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    if (!download_assets())
        return NULL;
    game->player = init_player();
    game->chest = chest_sprite();
    game->view = sfView_createFromRect(view_rect);
    game->window = init_window();
    game->scenes = init_scenes(game);
    game->sounds = menu_music();
    game->collisions = init_collision_img();
    if (!game->window || !game->scenes)
        return NULL;
    return game;
}
