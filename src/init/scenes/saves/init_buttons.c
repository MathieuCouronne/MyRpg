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

static void (*game_redirect_creation[3])(game_t *game) = {
    go_to_creation_player1, go_to_creation_player2, go_to_creation_player3
};

static button_t *init_button_saves(unsigned short i)
{
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};
    button_t *buttons = create_save_card(pos, SAVES_PATH, game_redirect[i]);

    if (!buttons)
        return NULL;
    return buttons;
}

static button_t *init_empty_button(unsigned short i)
{
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};
    button_t *buttons = create_save_card(pos, SAVES_EMPTY_PATH,
    game_redirect_creation[i]);

    if (!buttons)
        return NULL;
    return buttons;
}

static bool init_button(game_t *game, unsigned short i, button_t **buttons)
{
    if (!game->saves[i])
        buttons[i] = init_empty_button(i);
    else
        buttons[i] = init_button_saves(i);
    if (!buttons[i])
        return false;
    return true;
}

button_t **init_slots(game_t *game)
{
    sfVector2f pos = {0};
    button_t **buttons = malloc(sizeof(button_t) * 5);
    float shifts[3] = {5, 2, 1.25f};

    if (!buttons)
        return NULL;
    for (unsigned short i = 0; i < 3; i++) {
        if (!init_button(game, i, buttons))
            return NULL;
        pos.x = WINDOW_WIDTH / shifts[i] - (float) 462 / 2;
        pos.y = buttons[i]->asset->pos.y;
        sfSprite_setPosition(buttons[i]->asset->sprite, pos);
    }
    pos.x = 30;
    pos.y = 925;
    buttons[3] = create_icon(pos, SAVES_BACK_PATH, go_to_menu);
    buttons[4] = NULL;
    if (!buttons[0] || !buttons[1] || !buttons[2] || !buttons[3])
        return NULL;
    return buttons;
}
