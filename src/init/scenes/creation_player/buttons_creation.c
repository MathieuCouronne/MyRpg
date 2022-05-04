/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

extern const char *class_names[];

void up_class(game_t *game)
{
    if (game->scenes->creation_menu->class == 2)
        game->scenes->creation_menu->class = 0;
    else
        game->scenes->creation_menu->class += 1;
}

void down_class(game_t *game)
{
    if (game->scenes->creation_menu->class == 0)
        game->scenes->creation_menu->class = 2;
    else
        game->scenes->creation_menu->class -= 1;
}

void oui()
{

}

sfText **init_text_creation(sfFont *font)
{
    sfText **text = malloc(sizeof(sfText *) * 3);

    for (size_t i = 0; i < 3; i++) {
        text[i] = sfText_create();
        sfText_setFont(text[i], font);
        sfText_setString(text[i], class_names[i]);
        sfText_setCharacterSize(text[i], 20);
        sfText_setColor(text[i], sfWhite);
    }
    return text;
}

button_t **init_buttons_creation()
{
    button_t **buttons = malloc(sizeof(button_t) * 13);

    buttons[0] = create_icon((sfVector2f) {715, 505}, CREATION_PLUS_PATH, up_strength);
    buttons[1] = create_icon((sfVector2f) {715, 575}, CREATION_PLUS_PATH, up_defense);
    buttons[2] = create_icon((sfVector2f) {715, 645}, CREATION_PLUS_PATH, up_vitality);
    buttons[3] = create_icon((sfVector2f) {715, 720}, CREATION_PLUS_PATH, up_speed);
    buttons[4] = create_icon((sfVector2f) {715, 790}, CREATION_PLUS_PATH, up_dexterity);
    buttons[5] = create_icon((sfVector2f) {580, 505}, CREATION_LESS_PATH, oui);
    buttons[6] = create_icon((sfVector2f) {580, 575}, CREATION_LESS_PATH, oui);
    buttons[7] = create_icon((sfVector2f) {580, 645}, CREATION_LESS_PATH, oui);
    buttons[8] = create_icon((sfVector2f) {580, 720}, CREATION_LESS_PATH, oui);
    buttons[9] = create_icon((sfVector2f) {580, 790}, CREATION_LESS_PATH, oui);
    buttons[10] = create_icon((sfVector2f) {470, 355}, CREATION_ARROW_LEFT_PATH, down_class);
    buttons[11] = create_icon((sfVector2f) {720, 355}, CREATION_ARROW_RIGHT_PATH, up_class);
    buttons[12] = NULL;
    return buttons;
}
