/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

void oui()
{

}

button_t **init_buttons_creation()
{
    button_t **buttons = malloc(sizeof(button_t) * 6);

    buttons[0] = create_icon((sfVector2f) {715, 505}, CREATION_PLUS_PATH, oui);
    buttons[1] = create_icon((sfVector2f) {715, 575}, CREATION_PLUS_PATH, oui);
    buttons[2] = create_icon((sfVector2f) {715, 645}, CREATION_PLUS_PATH, oui);
    buttons[3] = create_icon((sfVector2f) {715, 720}, CREATION_PLUS_PATH, oui);
    buttons[4] = create_icon((sfVector2f) {715, 790}, CREATION_PLUS_PATH, oui);
    buttons[5] = create_icon((sfVector2f) {580, 505}, CREATION_LESS_PATH, oui);
    buttons[6] = create_icon((sfVector2f) {580, 575}, CREATION_LESS_PATH, oui);
    buttons[7] = create_icon((sfVector2f) {580, 645}, CREATION_LESS_PATH, oui);
    buttons[8] = create_icon((sfVector2f) {580, 720}, CREATION_LESS_PATH, oui);
    buttons[9] = create_icon((sfVector2f) {580, 790}, CREATION_LESS_PATH, oui);
    buttons[10] = NULL;
    return buttons;
}