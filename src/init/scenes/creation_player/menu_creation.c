/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

extern const int class_base_data[3][5];

static bool init_classes_base_data(int **stats)
{
    for (unsigned int i = 0; i < 3; i++) {
        stats[i] = malloc(sizeof(int) * 5);
        if (!stats[i])
            return false;
        for (unsigned int j = 0; j < 5; j++)
            stats[i][j] = class_base_data[i][j];
    }
    return true;
}

static game_asset_t *init_creation_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(CREATION_BG_PATH, NULL);
    if (!background->sprite || !background->texture)
        return NULL;
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

static int *unspent_init(void)
{
    int *unspent = malloc(sizeof(int) * 4);

    if (!unspent)
        return NULL;
    for (size_t i = 0; i < 3; i++)
        unspent[i] = 20;
    unspent[3] = -1;
    return unspent;
}

main_creation_scenes_t *init_creation(void)
{
    main_creation_scenes_t *scene = malloc(sizeof(main_creation_scenes_t));

    if (!scene)
        return NULL;
    scene->stats = malloc(sizeof(int *) * 6);
    scene->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    scene->background = init_creation_background();
    scene->buttons = init_buttons_creation();
    scene->text = init_text_creation(scene->font);
    init_classes_base_data(scene->stats);
    if (!scene->stats || !scene->font || !scene->background ||
        !scene->buttons || !scene->text)
        return NULL;
    scene->stat = create_stat_text(scene->font, scene);
    scene->unspent = unspent_init();
    scene->class = 0;
    scene->unspent_text = init_unspent(scene, scene->font);
    if (!scene->stat || !scene->unspent || !scene->unspent_text)
        return NULL;
    return scene;
}
