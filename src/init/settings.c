/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "menu.h"
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_settings_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(SETTINGS_BG_PATH, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

settings_t *init_settings(void)
{
    settings_t *scene = malloc(sizeof(main_menu_scenes_t));

    if (!scene)
        return NULL;
    scene->background = init_settings_background();
    //scene->buttons = init_buttons();
    return scene;
}
