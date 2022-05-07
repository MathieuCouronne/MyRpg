/*
** EPITECH PROJECT, 2021
** stats_scene.c
** File description:
** Stats initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

static bool init_classes_base_data(int *stats, game_t *game)
{
    if (!stats)
        return false;
    stats[0] = game->saves[game->current]->stats->strength;
    stats[1] = game->saves[game->current]->stats->defense;
    stats[2] = game->saves[game->current]->stats->vitality;
    stats[3] = game->saves[game->current]->stats->speed;
    stats[4] = game->saves[game->current]->stats->dexterity;
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

static sfText *create_unspent(sfFont *font, int i)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, itoa(i));
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f) {650, 450});
    return text;
}

stats_scene_t *init_stats(game_t *game)
{
    stats_scene_t *scene = malloc(sizeof(stats_scene_t));

    if (!scene)
        return NULL;
    scene->stats = malloc(sizeof(int *) * 6);
    scene->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    scene->background = init_creation_background();
    scene->buttons = init_buttons_stats();
    scene->text = init_text_class_scene(scene->font, game);
    init_classes_base_data(scene->stats, game);
    if (!scene->stats || !scene->font || !scene->background ||
        !scene->buttons || !scene->text)
        return NULL;
    scene->unspent = game->saves[game->current]->unspent;
    scene->stat = create_stat_text_scene(scene->font, scene);
    scene->unspent_text = create_unspent(scene->font, scene->unspent);
    if (!scene->stat || !scene->unspent_text)
        return NULL;
    return scene;
}
