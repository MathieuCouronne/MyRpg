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

button_t **init_buttons_stats(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 12);

    change_stat(buttons);
    buttons[10] = create_icon(
            (sfVector2f) {1400, 810}, CREATION_VALIDATE_PATH, back_to_game);
    buttons[11] = NULL;
    return buttons;
}
