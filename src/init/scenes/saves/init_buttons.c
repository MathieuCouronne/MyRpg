/*
** EPITECH PROJECT, 2021
** init_menu_button.c
** File description:
** init menu button
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

void go_back(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_MENU;
}

button_t **init_button_saves(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);

    if (!buttons)
        return NULL;
    buttons[0] = create_icon_buttons((sfVector2f) {30, 920},
    SAVES_BACK_PATH, go_back);
    buttons[1] = NULL;
    return buttons;

}
