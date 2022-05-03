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

game_asset_t *init_saves_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(MAIN_MENU_BG_PATH, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

game_asset_t *init_save_slot(sfVector2f pos)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->pos = pos;
    background->texture = sfTexture_createFromFile(SAVES_PATH, NULL);
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

game_asset_t **init_save(void)
{
    game_asset_t **saves = malloc(sizeof(game_asset_t *) * 5);

    if (!saves)
        return NULL;
    saves[0] = init_saves_background();
    return saves;
}

scene_saves_t *init_saves(character_t **saves)
{
    scene_saves_t *scene = malloc(sizeof(scene_saves_t));

    if (!scene)
        return NULL;
    scene->background = init_save();
    scene->buttons = init_slot(saves);
    scene->character = init_character(saves);
    set_pos_character(scene->character);
    return scene;
}
