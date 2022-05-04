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
        default_event_handling(game, game->scenes->creation_menu->buttons);
    }
}

bool display_creation(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_creation_scenes_t *creation = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->creation_menu)
        return false;
    window = game->window;
    creation = game->scenes->creation_menu ;
    buttons = creation->buttons;
    event_handling(game);
    sfRenderWindow_drawSprite(window, creation->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[3]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[4]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[5]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[6]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[7]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[8]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[9]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[10]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(window, creation->buttons[11]->asset->sprite, NULL);
    sfSprite_setScale(game->characters[creation->class]->sprite, (sfVector2f) {0.2f, 0.2f});
    sfRenderWindow_drawSprite(window, game->characters[creation->class]->sprite, NULL);
    return true;
}
