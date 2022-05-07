/*
** EPITECH PROJECT, 2021
** title.c
** File description:
** tile menu initializer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"
#include "macros.h"

button_t *title_menu(char *str)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f pos;
    sfFloatRect rect;

    button->asset = malloc(sizeof(game_asset_t));
    button->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    button->text = sfText_create();
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, str);
    sfText_setCharacterSize(button->text, 100);
    sfText_setColor(button->text, sfYellow);
    rect = sfText_getGlobalBounds(button->text);
    pos = (sfVector2f) {1920 / 2  - (rect.width / 2), 1080 / 6};
    sfText_setPosition(button->text, pos);
    sfText_setOutlineColor(button->text, sfBlue);
    sfText_setOutlineThickness(button->text, -1);
    return button;
}
