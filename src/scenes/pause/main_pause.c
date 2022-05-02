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

bool display_pause(game_t *game)
{
    scenes_t *scenes = game->scenes;
    pause_t *pause = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !scenes || !scenes->game_scene->pause
    || !scenes->game_scene->pause->active)
        return false;
    pause = game->scenes->game_scene->pause;
    buttons = pause->buttons;
    sfRenderWindow_drawSprite(game->window, pause->background->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(game->window, buttons[0]->text, NULL);
    sfRenderWindow_drawSprite(game->window, buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawText(game->window, buttons[1]->text, NULL);
    sfRenderWindow_drawSprite(game->window, buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawText(game->window, buttons[2]->text, NULL);
    sfRenderWindow_drawSprite(game->window, buttons[3]->asset->sprite, NULL);
    sfRenderWindow_drawText(game->window, buttons[3]->text, NULL);
    return true;
}
