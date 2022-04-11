/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

bool display_main_menu(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_menu_scenes_t *menu = NULL;
    menu_buttons_t *buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->main_menu ||
    !game->scenes->main_menu->buttons)
        return false;
    window = game->window;
    menu = game->scenes->main_menu;
    buttons = menu->buttons;
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons->play->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons->play->text, NULL);
    sfRenderWindow_drawSprite(window, buttons->settings->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons->settings->text, NULL);
    sfRenderWindow_drawText(window, buttons->title->text, NULL);
    return true;
}