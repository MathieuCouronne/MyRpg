/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (handle_buttons_clicks(game, game->scenes->saves->buttons))
            return;
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
    sfRenderWindow_drawSprite(window, saves->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[3]->asset->sprite, NULL);
    for (size_t i = 0; saves->character[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window, saves->character[i]->sprite, NULL);
    }
    return true;
}
