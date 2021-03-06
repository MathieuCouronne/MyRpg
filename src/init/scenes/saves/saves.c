/*
** EPITECH PROJECT, 2021
** saves.c
** File description:
** Same initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_saves_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(SAVES_BG_PATH, NULL);
    if (!background->sprite || !background->texture)
        return NULL;
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

scene_saves_t *init_saves(game_t *game)
{
    scene_saves_t *scene = malloc(sizeof(scene_saves_t));

    if (!scene || !game || !game->saves)
        return NULL;
    scene->background = init_saves_background();
    scene->buttons = init_slots(game);
    scene->character = init_character(game->saves);
    if (!scene->background || !scene->buttons || !scene->character)
        return NULL;
    return scene;
}
