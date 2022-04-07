/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"

button_t *init_button(char *str, sfVector2f pos)
{
    button_t *button = malloc(sizeof(button_t));

    button->font = sfFont_createFromFile("./font/LifeCraft_Font.ttf");
    button->text = sfText_create();
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, str);
    sfText_setCharacterSize(button->text, 100);
    sfText_setColor(button->text, sfRed);
    // button->asset->pos = pos;
    sfText_setPosition(button->text, pos);
    return button;
}

buttons_t *init_buttons(void)
{
    buttons_t *button = malloc(sizeof(buttons_t));

    button->play = init_button("Play", (sfVector2f){900,500} );
    return button;
}
