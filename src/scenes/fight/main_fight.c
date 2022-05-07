/*
** EPITECH PROJECT, 2021
** main_fight.c
** File description:
** display fight
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include <stdlib.h>

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->fight->buttons);
    }
}

static void display_text(game_t *game, sfRenderWindow *window, fight_t *fight)
{
    sfRenderWindow_drawText(window, fight->text_player_hp, NULL);
    sfRenderWindow_drawText(window, fight->text_enemy_hp, NULL);
}

static void draw_sprites(sfRenderWindow *window,
    fight_t *fight, game_t *game)
{
    sfRenderWindow_drawSprite(window, fight->background_fight->sprite, NULL);
    sfRenderWindow_drawSprite(window,
        fight->enemy[game->enemy_id]->sprite, NULL);
    sfRenderWindow_drawSprite(window,
        fight->characters[game->saves[game->current]->class]->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->text_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->player_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->enemy_bar->sprite, NULL);
    display_text(game, window, fight);
}

bool display_fight(game_t *game)
{
    sfRenderWindow *window = NULL;
    fight_t *fight = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->fight)
        return false;
    event_handling(game);
    window = game->window;
    fight = game->scenes->fight;
    draw_sprites(window, fight, game);
    for (unsigned int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window,
            fight->buttons[i]->asset->sprite, NULL);
        sfRenderWindow_drawText(window, fight->buttons[i]->text, NULL);
    }
    return true;
}
