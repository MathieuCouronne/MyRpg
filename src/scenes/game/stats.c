/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** create creation player scene
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

extern const char *class_textures[];

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->stats->buttons);
    }
}

static void display_buttons_creation(sfRenderWindow *w, stats_scene_t *stats)
{
    for (size_t i = 0; i < 11; i ++) {
        sfRenderWindow_drawSprite(w, stats->buttons[i]->asset->sprite, NULL);
    }
    sfRenderWindow_drawText(w, stats->unspent_text, NULL);
    sfRenderWindow_drawText(w,stats->stat[6], NULL);
}

static void display_stat(stats_scene_t *stats, sfRenderWindow *window)
{
    for (size_t i = 0; i < 5; i++) {
        sfRenderWindow_drawText(window,
        stats->stat[0], NULL);
        sfRenderWindow_drawText(window,
        stats->stat[1], NULL);
        sfRenderWindow_drawText(window,
        stats->stat[2], NULL);
        sfRenderWindow_drawText(window,
        stats->stat[3], NULL);
        sfRenderWindow_drawText(window,
        stats->stat[4], NULL);
    }
}

void set_parameters(game_t *game)
{
    sfSprite_setPosition(game->characters[game->saves
    [game->current]->class]->sprite,(sfVector2f) {940, 270});
    sfSprite_setScale(game->characters[game->saves
    [game->current]->class]->sprite,(sfVector2f) {8.f, 8.f});
}

bool display_stats(game_t *game)
{
    sfRenderWindow *window = NULL;
    stats_scene_t *stats = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->stats) {
        printf("je afdsfq<\n");
        return false;
    }
    window = game->window;
    stats = game->scenes->stats;
    event_handling(game);
    sfRenderWindow_drawSprite(window, stats->background->sprite, NULL);
    display_buttons_creation(window, stats);
    set_parameters(game);
    sfRenderWindow_drawSprite(window,game->characters[game->saves
    [game->current]->class]->sprite, NULL);
    sfText_setPosition(stats->text,(sfVector2f) {540, 360});
    sfRenderWindow_drawText(window, stats->text, NULL);
    display_stat(stats, window);
    return true;
}
