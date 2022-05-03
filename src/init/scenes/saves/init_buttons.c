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
    button_t **buttons = malloc(sizeof(button_t *) * 5);

    if (!buttons)
        return NULL;
    buttons[0] = create_icon_buttons((sfVector2f) {30, 920},
    SAVES_BACK_PATH, go_back);
    buttons[1] = create_icon_buttons((sfVector2f)
    {WINDOW_WIDTH / 1.25 - 512 / 2, WINDOW_HEIGHT / 2 - 850 / 2}, SAVES_PATH,
    go_to_game);
    buttons[2] = create_icon_buttons((sfVector2f)
    {WINDOW_WIDTH / 2 - 512 / 2 , WINDOW_HEIGHT / 2 - 850 / 2}, SAVES_PATH,
    go_to_game);
    buttons[3] = create_icon_buttons((sfVector2f)
    {WINDOW_WIDTH / 5 - 512 / 2, WINDOW_HEIGHT / 2 - 850 / 2 }, SAVES_PATH,
    go_to_game);
    buttons[4] = NULL;
    return buttons;

}
