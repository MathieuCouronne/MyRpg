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
    sfTexture_destroy(button->asset->texture);
    sfSprite_destroy(button->asset->sprite);
    sfFont_destroy(button->font);
    sfText_destroy(button->text);
    free(button);
}

void destroy_icons(button_t *button)
{
    if (!button)
        return;
    sfTexture_destroy(button->asset->texture);
    sfSprite_destroy(button->asset->sprite);
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
            destroy_icons(buttons[i]);
    }
    free(buttons);
}
