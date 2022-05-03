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
        default_event_handling(game, game->scenes->pause->buttons);
        if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyEscape) {
            game->scenes->prev = game->scenes->current;
            game->scenes->current = MAIN_GAME;
        }
    }
}
main_game_t *copy_game(game_t *game)
{
    main_game_t *copy = NULL;

    copy = game->scenes->game_scene;
    return copy;

}

bool display_pause(game_t *game)
{
    sfRenderWindow *window = NULL;
    pause_t *pause = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->pause ||
        !game->scenes->pause->buttons)
        return false;
    window = game->window;
    pause = game->scenes->pause;
    buttons = pause->buttons;
    event_handling(game);
    sfRenderWindow_drawSprite(window, pause->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[1]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[2]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[3]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[3]->text, NULL);
    return true;
}
