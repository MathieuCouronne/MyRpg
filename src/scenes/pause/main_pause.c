/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"
#include "macros.h"

bool display_pause(game_t *game, sfRenderWindow *window)
{
    pause_t *pause = NULL;
    button_t **buttons = NULL;
    sfVector2f pos;

    if (!game || !game->window || !game->scenes || !game->scenes->game_scene->pause)
        return false;
    pause = game->scenes->game_scene->pause;
    buttons = pause->buttons;
    pos.x = game->player->position->x - WINDOW_HEIGHT / 2;
    pos.y = game->player->position->y - WINDOW_HEIGHT / 2;
    sfRenderWindow_drawSprite(window, pause->background->sprite, NULL);
    sfSprite_setPosition(pause->background->sprite, pos);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[3]->asset->sprite, NULL);
    return true;
}