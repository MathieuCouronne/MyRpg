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

static bool init_classes_base_data(int *stats, game_t *game)
{
    if (!stats)
        return false;
    for (unsigned int j = 0; j < 5; j++)
        stats[j] = class_base_data[game->saves[game->current]->class][j];
    return true;
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
    scene->stat = create_stat_text_scene(scene->font, scene);
    scene->unspent = game->saves[game->current]->unspent;
    scene->unspent_text = game->scenes->creation_menu->unspent_text
    [game->scenes->creation_menu->class];
    if (!scene->stat || !scene->unspent || !scene->unspent_text)
        return NULL;
    return scene;
}
