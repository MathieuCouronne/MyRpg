/*
** EPITECH PROJECT, 2021
** loader.c
** File description:
** Display loader
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "macros.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

bool display_credits(game_t *game)
{
    sfRenderWindow *window = NULL;
    credits_t *credits = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->credits)
        return false;
    event_handling(game);
    window = game->window;
    credits = game->scenes->credits;
    sfRenderWindow_drawSprite(window, credits->background->sprite, NULL);
    return true;
}
