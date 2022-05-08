/*
** EPITECH PROJECT, 2021
** button.c
** File description:
** button destroyer
*/

#include "my_rpg.h"
#include <stdlib.h>

void destroy_button(button_t *button)
{
    if (!button)
        return;
    if (button->asset->texture)
        sfTexture_destroy(button->asset->texture);
    if (button->asset->sprite)
        sfSprite_destroy(button->asset->sprite);
    if (button->text)
        sfText_destroy(button->text);
    free(button);
}

void menu_destroy_buttons(button_t **buttons)
{
    if (!buttons)
        return;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (buttons[i])
            destroy_button(buttons[i]);
    }
    free(buttons);
}

void settings_destroy_icons(button_t **buttons)
{
    if (!buttons)
        return;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (buttons[i])
            destroy_button(buttons[i]);
    }
    free(buttons);
}
