/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include "game.h"
#include <stdlib.h>

bool display_fight(game_t *game)
{
    sfRenderWindow *window = NULL;
    fight_t *fight = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->fight)
        return false;
    window = game->window;
    fight = game->scenes->fight;
    sfRenderWindow_drawSprite(window, fight->background_fight->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->ennemy->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->player->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->text_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->hp_bar->sprite, NULL);
    sfRenderWindow_drawText(window, fight->text->text, NULL);
    return true;
}