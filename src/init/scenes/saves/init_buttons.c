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

static void go_back(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_MENU;
}

static button_t *init_button_saves(void)
{
    button_t *buttons = malloc(sizeof(button_t));
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};

    if (!buttons)
        return NULL;
    buttons = create_icon_buttons(pos, SAVES_PATH, go_to_game);
    return buttons;
}

static button_t *init_empty_button(void)
{
    button_t *buttons = malloc(sizeof(button_t));
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};

    if (!buttons)
        return NULL;
    buttons = create_icon_buttons(pos, SAVES_EMPTY_PATH, go_to_game);
    return buttons;
}

button_t **init_slots(character_t **saves)
{
    sfVector2f pos = {0};
    button_t **buttons = malloc(sizeof(button_t) * 5);
    float shifts[3] = {5, 2, 1.25f};

    for (size_t i = 0; i < 3; i++) {
        if (!saves[i])
            buttons[i] = init_empty_button();
        else
            buttons[i] = init_button_saves();
        pos.x = WINDOW_WIDTH / shifts[i] - (float) 462 / 2;
        pos.y = buttons[i]->asset->pos.y;
        sfSprite_setPosition(buttons[i]->asset->sprite, pos);
    }
    pos.x = 30;
    pos.y = 768;
    buttons[3] = create_icon_buttons(pos, SAVES_BACK_PATH, go_back);
    buttons[4] = NULL;
    return buttons;
}
