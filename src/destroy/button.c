/*
** EPITECH PROJECT, 2021
** button.c
** File description:
** button destroyer
*/

#include "menu.h"
#include "my_rpg.h"
#include <stdlib.h>

void destroy_button(button_t *button)
{
    if (!button)
        return;
    sfFont_destroy(button->font);
    sfText_destroy(button->text);
    free(button);
}

void menu_destroy_buttons(menu_buttons_t *button)
{
    if (!button)
        return;
    destroy_button(button->settings);
    destroy_button(button->play);
    destroy_button(button->title);
    free(button);
}
