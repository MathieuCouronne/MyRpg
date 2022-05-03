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
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 850.f / 2};

    if (!buttons)
        return NULL;
    buttons = create_icon_buttons(pos, SAVES_PATH, go_to_game);
    return buttons;
}

button_t *init_empty_button(void)
{
    button_t *buttons = malloc(sizeof(button_t));
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 850.f / 2};

    if (!buttons)
        return NULL;
    buttons = create_icon_buttons(pos, SAVES_EMPTY_PATH, go_to_game);
    return buttons;
}

button_t **init_slot(character_t **saves)
{
    button_t **buttons = malloc(sizeof(button_t) * 5);

    for (size_t i = 0; i < 3; i++) {
        if (!saves[i])
            buttons[i] = init_empty_button();
        else
            buttons[i] = init_button_saves();
    }
    sfSprite_setPosition(buttons[0]->asset->sprite,
        (sfVector2f) {WINDOW_WIDTH / 5 - 512 / 2, buttons[0]->asset->pos.y});
    sfSprite_setPosition(buttons[1]->asset->sprite,
        (sfVector2f) {WINDOW_WIDTH / 2 - 512 / 2, buttons[1]->asset->pos.y});
    sfSprite_setPosition(buttons[2]->asset->sprite,
        (sfVector2f) {WINDOW_WIDTH / 1.25 - 512 / 2, buttons[2]->asset->pos.y});
    buttons[3] = create_icon_buttons((sfVector2f) {30, 920},
        SAVES_BACK_PATH, go_back);
    buttons[4] = NULL;
    return buttons;
}
