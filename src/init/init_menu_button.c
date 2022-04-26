/*
** EPITECH PROJECT, 2021
** init_menu_button.c
** File description:
** init menu button
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"
#include "my_rpg.h"

menu_buttons_t *init_buttons(void)
{
    menu_buttons_t *button = malloc(sizeof(menu_buttons_t));

    button->play = create_button("Play",
                            (sfVector2f){960 - 350 / 2,500});
    button->settings = create_button("Settings",
                            (sfVector2f){960 - 350 / 2 ,650});
    button->title = title_menu("Cyber_Coc");
    return button;
}
