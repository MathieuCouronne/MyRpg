/*
** EPITECH PROJECT, 2021
** init_menu_button.c
** File description:
** init menu button
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"

menu_buttons_t *init_buttons(void)
{
    menu_buttons_t *button = malloc(sizeof(menu_buttons_t));

    button->play = create_button("Play", (sfVector2f){920,530},
                               (sfVector2f){800,500});
    button->settings = create_button("Settings",(sfVector2f){885,680},
                                   (sfVector2f){800,650});
    return button;
}
