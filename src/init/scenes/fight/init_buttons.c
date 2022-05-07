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

button_t **init_attack_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    sfVector2f scale = {2.35, 1};

    if (!buttons)
        return NULL;
    buttons[0] = create_button("Bite", (sfVector2f) {33, 779}, attack_enemy,
        scale);
    buttons[1] = create_button("Iron Claws",(sfVector2f) {967, 779},
        go_to_settings, scale);
    buttons[2] = create_button("Giga",(sfVector2f) {33, 890},
        go_to_settings, scale);
    buttons[3] = create_button("Bouffon",(sfVector2f) {967, 890},
        go_to_settings, scale);
    buttons[4] = NULL;
    if (!buttons[0] || !buttons[1] || !buttons[2] || !buttons[3])
        return NULL;
    return buttons;
}
