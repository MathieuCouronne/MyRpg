/*
** EPITECH PROJECT, 2021
** scene_saves.c
** File description:
** display saves scene
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->saves->buttons);
    }
}

bool display_saves(game_t *game)
{
    sfRenderWindow *window = NULL;
    scene_saves_t *saves = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->main_menu ||
        !game->scenes->main_menu->buttons)
        return false;
    event_handling(game);
    window = game->window;
    saves = game->scenes->saves;
    buttons = saves->buttons;
    sfRenderWindow_drawSprite(window, saves->background->sprite, NULL);
    for (size_t i = 0; buttons[i]; i++)
        sfRenderWindow_drawSprite(window, buttons[i]->asset->sprite, NULL);
    for (size_t i = 0; i < 3; i++) {
        if (!saves->character[i])
            continue;
        sfRenderWindow_drawSprite(window, saves->character[i]->sprite, NULL);
    }
    return true;
}
