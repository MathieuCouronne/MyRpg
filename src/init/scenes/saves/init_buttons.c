/*
** EPITECH PROJECT, 2021
** init_buttons.c
** File description:
** Init slots saves menu
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

static button_t *init_button_saves(unsigned short i, game_t *game)
{
    sfVector2f pos = {0, (float) WINDOW_HEIGHT / 2 - 768.f / 2};
    button_t *buttons = create_save_card(pos, SAVES_PATH, game_redirect[i]);

    if (!buttons)
        return NULL;
    buttons->text = create_pseudo_txt(game, i, buttons);
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
    else {
        buttons[i] = init_button_saves(i, game);
    }
    if (!buttons[i])
        return false;
    return true;
}

static void set_pos_text(button_t *buttons, sfVector2f pos, float shifts)
{
    sfVector2f pos_txt;
    sfFloatRect n;
    unsigned int size;
    sfFloatRect rect = sfSprite_getGlobalBounds(buttons->asset->sprite);;

    pos.x = WINDOW_WIDTH / shifts - (float) 462 / 2;
    pos.y = buttons->asset->pos.y;
    pos_txt = pos;
    if (!buttons->text);
    else {
        n = sfText_getGlobalBounds(buttons->text);
        size = sfText_getCharacterSize(buttons->text);
        pos_txt.x += (rect.width / 2 - n.width) + (float) size + n.height;
        pos_txt.y += rect.height / 2 + (rect.height / 2 - 130);
        sfText_setPosition(buttons->text, pos_txt);
    }
    sfSprite_setPosition(buttons->asset->sprite, pos);
}

button_t **init_slots(game_t *game)
{
    sfVector2f pos = {0};
    button_t **buttons = malloc(sizeof(button_t) * 5);
    float shifts[3] = {5, 2, 1.25f};

    if (!buttons)
        return NULL;
    for (unsigned short i = 0; i < 3; i++) {
        if (!init_button(game, i, buttons)) {
            return NULL;
        }
        set_pos_text(buttons[i], pos, shifts[i]);
    }
    pos.x = 30;
    pos.y = 925;
    buttons[3] = create_icon(pos, SAVES_BACK_PATH, go_to_menu);
    buttons[4] = NULL;
    if (!buttons[0] || !buttons[1] || !buttons[2] || !buttons[3])
        return NULL;
    return buttons;
}
