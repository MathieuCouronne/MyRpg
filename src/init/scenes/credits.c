/*
** EPITECH PROJECT, 2021
** pause.c
** File description:
** Pause initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

static game_asset_t *init_credits_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(CREDITS_BG_PATH, NULL);
    if (!background->sprite || !background->texture)
        return NULL;
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

credits_t *init_credits(void)
{
    credits_t *scene = malloc(sizeof(credits_t));

    if (!scene)
        return NULL;
    scene->background = init_credits_background();
    return scene;
}
