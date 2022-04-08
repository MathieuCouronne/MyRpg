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
    sfRenderWindow *window = game->window;
    main_menu_scenes_t *menu = game->scenes->main_menu;
    menu_buttons_t *buttons = menu->buttons;

    if (!menu)
        return false;
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons->play->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons->play->text, NULL);
    sfRenderWindow_drawSprite(window, buttons->settings->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons->settings->text, NULL);
    return true;
}