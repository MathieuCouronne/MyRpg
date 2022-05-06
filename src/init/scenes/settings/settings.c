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

game_asset_t *init_settings_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(SETTINGS_BG_PATH, NULL);
    if (!background->sprite || !background->texture)
        return NULL;
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

button_t **init_buttons_settings(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);
    float pos_x = 960 - 390 / 2;

    if (!buttons)
        return NULL;
    buttons[0] = create_button("Confirm", (sfVector2f) {pos_x, 870},
    go_to_prev,(sfVector2f) {1, 1});
    buttons[1] = NULL;
    if (!buttons[0])
        return NULL;
    return buttons;
}

settings_t *init_settings(void)
{
    settings_t *scene = malloc(sizeof(settings_t));

    if (!scene)
        return NULL;
    scene->background = init_settings_background();
    scene->buttons = init_buttons_settings();
    scene->icons = init_icons_settings();
    if (!scene->background || !scene->buttons || !scene->icons)
        return NULL;
    return scene;
}