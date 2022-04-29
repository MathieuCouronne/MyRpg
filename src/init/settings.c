/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "menu.h"
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
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

void go_to_prev(game_t *game)
{
    game->scenes->current = game->scenes->prev;
}

button_t **init_buttons_settings(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 6);
    float pos_x = 960 - 390 / 2;
    float icons = 960 - 41 / 2;

    buttons[0] = create_button("Validate", (sfVector2f) {pos_x ,870}, go_to_prev);
    buttons[1] = create_icon((sfVector2f) {icons ,640}, BUTTON_SETTINGS_PATH);
    buttons[2] = create_icon((sfVector2f) {icons ,700}, BUTTON_SETTINGS_PATH);
    buttons[3] = create_icon((sfVector2f) {icons ,760}, BUTTON_SETTINGS_PATH);
    buttons[4] = create_icon((sfVector2f) {icons ,820}, BUTTON_SETTINGS_PATH);
    buttons[5] = NULL;
    return buttons;
}

settings_t *init_settings(void)
{
    settings_t *scene = malloc(sizeof(settings_t));

    if (!scene)
        return NULL;
    scene->background = init_settings_background();
    scene->buttons = init_buttons_settings();
    return scene;
}
