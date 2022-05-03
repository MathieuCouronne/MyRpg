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

button_t *init_button_saves(void)
{
    button_t *buttons = malloc(sizeof(button_t));

    if (!buttons)
        return NULL;
    buttons = create_icon_buttons((sfVector2f)
    (sfVector2f) {0,0}, SAVES_PATH,
            go_to_game);
    return buttons;
}

button_t *init_empty_button(void)
{
    button_t *buttons = malloc(sizeof(button_t));

    if (!buttons)
        return NULL;
    buttons = create_icon_buttons((sfVector2f)
    (sfVector2f) {0,0}, SAVES_EMPTY_PATH, go_to_game);
    return buttons;
}

button_t **init_slot(character_t **saves)
{
    button_t **buttons = malloc(sizeof(button_t) * 5);

    for (size_t i = 0; i != 3; i++) {
        if (!saves[i])
            buttons[i] = init_empty_button();
        else
            buttons[i] = init_button_saves();
    }
    sfSprite_setPosition(buttons[0]->asset->sprite,
                         (sfVector2f) {WINDOW_WIDTH / 1.25 - 512 / 2, WINDOW_HEIGHT / 2 - 850 / 2});
    sfSprite_setPosition(buttons[1]->asset->sprite,
                         (sfVector2f) {WINDOW_WIDTH / 2 - 512 / 2, WINDOW_HEIGHT / 2 - 850 / 2});
    sfSprite_setPosition(buttons[2]->asset->sprite,
                         (sfVector2f) {WINDOW_WIDTH / 5 - 512 / 2, WINDOW_HEIGHT / 2 - 850 / 2});
    buttons[3] = create_icon_buttons((sfVector2f) {30, 920},
                                     SAVES_BACK_PATH, go_back);
    buttons[4] = NULL;
    return buttons;
}
