/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Display main menu
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->main_menu->buttons);
        default_event_handling(game, game->scenes->main_menu->icon);
    }
}

bool display_main_menu(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_menu_scenes_t *menu = NULL;
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->main_menu ||
    !game->scenes->main_menu->buttons)
        return false;
    event_handling(game);
    window = game->window;
    menu = game->scenes->main_menu;
    buttons = menu->buttons;
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[1]->text, NULL);
    sfRenderWindow_drawSprite(window, buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[2]->text, NULL);
    sfRenderWindow_drawSprite(window, menu->icon[0]->asset->sprite, NULL);
    return true;
}
