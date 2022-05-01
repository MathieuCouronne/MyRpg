/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "structs.h"
#include "macros.h"

text_t *init_text(char *str)
{
    text_t *text = malloc(sizeof(text_t));
    sfVector2f pos;
    sfFloatRect rect;

    text->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    text->text = sfText_create();
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, str);
    sfText_setCharacterSize(text->text, 50);
    sfText_setColor(text->text, sfWhite);
    pos = (sfVector2f) {60, 830};
    sfText_setPosition(text->text, pos);
    return text;
}
