/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
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

bool display_fight(game_t *game)
{
    sfRenderWindow *window = NULL;
    fight_t *fight = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->fight)
        return false;
    event_handling(game);
    window = game->window;
    fight = game->scenes->fight;
    sfRenderWindow_drawSprite(window, fight->background_fight->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->enemy->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->player->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->text_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->player_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->enemy_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->buttons[3]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, fight->buttons[0]->text, NULL);
    sfRenderWindow_drawText(window, fight->buttons[1]->text, NULL);
    sfRenderWindow_drawText(window, fight->buttons[2]->text, NULL);
    sfRenderWindow_drawText(window, fight->buttons[3]->text, NULL);
    return true;
}
