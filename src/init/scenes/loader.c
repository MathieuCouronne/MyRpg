/*
** EPITECH PROJECT, 2021
** loader.c
** File description:
** Init all sprite for loading
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "macros.h"
#include "my_rpg.h"

static game_asset_t *init_background(void)
{
    game_asset_t *bar = malloc(sizeof(game_asset_t));
    sfIntRect rect = {0, 0, LOADER_WINDOW_WIDTH, LOADER_WINDOW_HEIGHT};
    sfVector2f pos = {0, 0};

    if (!bar)
        return NULL;
    bar->rect = &rect;
    bar->sprite = sfSprite_create();
    if (!bar->sprite)
        return NULL;
    bar->texture = sfTexture_createFromFile(LOADER_BAR_BG_PATH, NULL);
    sfSprite_setPosition(bar->sprite, pos);
    sfSprite_setTextureRect(bar->sprite, rect);
    sfSprite_setTexture(bar->sprite, bar->texture, false);
    return bar;
}

static game_asset_t *init_loader_bar(void)
{
    game_asset_t *bar = malloc(sizeof(game_asset_t));
    sfIntRect rect = {0, 0, 439, 78};
    sfVector2f pos = {
        (float) LOADER_WINDOW_WIDTH / 2 - (float) rect.width / 2,
        (float) LOADER_WINDOW_HEIGHT / 2 - (float) rect.height / 2
    };

    if (!bar)
        return NULL;
    bar->rect = &rect;
    bar->sprite = sfSprite_create();
    if (!bar->sprite)
        return NULL;
    bar->texture = sfTexture_createFromFile(LOADER_BAR_PATH, NULL);
    sfSprite_setPosition(bar->sprite, pos);
    sfSprite_setTextureRect(bar->sprite, rect);
    sfSprite_setTexture(bar->sprite, bar->texture, false);
    return bar;
}

static game_asset_t *init_loader_fill(void)
{
    game_asset_t *bar = malloc(sizeof(game_asset_t));
    sfIntRect rect = {0, 0, 439, 78};
    sfVector2f pos = {
        (float) LOADER_WINDOW_WIDTH / 2 - (float) rect.width / 2,
        (float) LOADER_WINDOW_HEIGHT / 2 - (float) rect.height / 2
    };

    if (!bar)
        return NULL;
    bar->rect = &rect;
    bar->sprite = sfSprite_create();
    if (!bar->sprite)
        return NULL;
    bar->texture = sfTexture_createFromFile(LOADER_FILL_PATH, NULL);
    sfSprite_setPosition(bar->sprite, pos);
    sfSprite_setTextureRect(bar->sprite, rect);
    sfSprite_setTexture(bar->sprite, bar->texture, false);
    return bar;
}

static void init(loader_t *scene)
{
    scene->event = (sfEvent) {0};
    scene->background = init_background();
    scene->bar = init_loader_bar();
    scene->fill = init_loader_fill();
}

loader_t *init_loader_window(void)
{
    sfVideoMode desktop_mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS};
    sfVideoMode mode = {LOADER_WINDOW_WIDTH, LOADER_WINDOW_HEIGHT, WINDOW_BITS};
    loader_t *scene = malloc(sizeof(loader_t));
    sfVector2i pos = {
        (int) (desktop_mode.width / 2 - mode.width / 2),
        (int) (desktop_mode.height / 2 - mode.height / 2)
    };

    if (!scene)
        return NULL;
    scene->window = sfRenderWindow_create(mode, NULL, sfNone, NULL);
    if (!scene->window)
        return NULL;
    sfRenderWindow_setPosition(scene->window, pos);
    init(scene);
    if (!scene->bar || !scene->fill)
        return NULL;
    return scene;
}
