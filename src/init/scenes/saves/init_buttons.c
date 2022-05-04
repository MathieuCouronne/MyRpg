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

static void (*game_redirect[3])(game_t *game) = {
    go_to_game_player1, go_to_game_player2, go_to_game_player3
};

static button_t *init_button_saves(unsigned short i)
{
    button_t *buttons = malloc(sizeof(button_t));
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};

    if (!buttons)
        return NULL;
    buttons = create_save_card(pos, SAVES_PATH, game_redirect[i]);
    return buttons;
}

static button_t *init_empty_button(void)
{
    button_t *buttons = malloc(sizeof(button_t));
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};

    if (!buttons)
        return NULL;
    buttons = create_save_card(pos, SAVES_EMPTY_PATH, go_to_creation);
    return buttons;
}

button_t **init_slots(game_t *game)
{
    sfVector2f pos = {0};
    button_t **buttons = malloc(sizeof(button_t) * 5);
    float shifts[3] = {5, 2, 1.25f};

    for (unsigned short i = 0; i < 3; i++) {
        if (!game->saves[i])
            buttons[i] = init_empty_button();
        else
            buttons[i] = init_button_saves(i);
        pos.x = WINDOW_WIDTH / shifts[i] - (float) 462 / 2;
        pos.y = buttons[i]->asset->pos.y;
        sfSprite_setPosition(buttons[i]->asset->sprite, pos);
    }
    pos.x = 30;
    pos.y = 768;
    buttons[3] = create_icon(pos, SAVES_BACK_PATH);
    buttons[3]->on_click = go_to_menu;
    buttons[4] = NULL;
    return buttons;
}
