/*
** EPITECH PROJECT, 2021
** buttons_creation.c
** File description:
** Create button for stats menu
*/

#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

extern const char *class_names[];

sfText *init_text_class_scene(sfFont *font, game_t *game)
{
    sfText *text;

    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, class_names[game->saves[game->current]->class]);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    return text;
}

static void change_stat(button_t **buttons)
{
    buttons[0] = create_icon(
            (sfVector2f) {715, 505}, CREATION_PLUS_PATH, up_strength_game);
    buttons[1] = create_icon(
            (sfVector2f) {715, 575}, CREATION_PLUS_PATH, up_defense_game);
    buttons[2] = create_icon(
            (sfVector2f) {715, 645}, CREATION_PLUS_PATH, up_vitality_game);
    buttons[3] = create_icon(
            (sfVector2f) {715, 720}, CREATION_PLUS_PATH, up_speed_game);
    buttons[4] = create_icon(
            (sfVector2f) {715, 790}, CREATION_PLUS_PATH, up_dexterity_game);
    buttons[5] = create_icon(
            (sfVector2f) {580, 505}, CREATION_LESS_PATH, down_strength_game);
    buttons[6] = create_icon(
            (sfVector2f) {580, 575}, CREATION_LESS_PATH, down_defense_game);
    buttons[7] = create_icon(
            (sfVector2f) {580, 645}, CREATION_LESS_PATH, down_vitality_game);
    buttons[8] = create_icon(
            (sfVector2f) {580, 720}, CREATION_LESS_PATH, down_speed_game);
    buttons[9] = create_icon(
            (sfVector2f) {580, 790}, CREATION_LESS_PATH, down_dexterity_game);
}

button_t **init_buttons_stats(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 12);

    change_stat(buttons);
    buttons[10] = create_icon(
            (sfVector2f) {1400, 810}, CREATION_VALIDATE_PATH, back_to_game);
    buttons[11] = NULL;
    return buttons;
}
