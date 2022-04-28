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
    button_t **buttons = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->main_menu ||
    !game->scenes->main_menu->buttons)
        return false;
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
    // sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    play_music(game->sounds->menu);
    return true;
}
