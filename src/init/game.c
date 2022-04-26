/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scenes.h"
#include "fight.h"
#include "macros.h"

static sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "MyRPG",
    sfFullscreen, NULL);

    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

scenes_t *init_scenes(game_t *game)
{
    scenes_t *scenes = malloc(sizeof(scenes_t));

    scenes->main_menu = init_main_menu();
    scenes->game_scene = init_main_game(game);
    return scenes;
}

sfImage *init_collision_img(void)
{
    sfImage *image = sfImage_createFromFile("./assets/images/collisions.jpg");

    if (!image)
        return NULL;
    return image;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfFloatRect view_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    game->player = character_sprite();
    game->view = sfView_createFromRect(view_rect);
    game->window = init_window();
    game->scenes = init_scenes(game);
    game->sound = menu_music();
    game->scenes->fight = init_fight();
    game->collisions = init_collision_img();
    if (!game->window || !game->scenes)
        return NULL;
    return game;
}
