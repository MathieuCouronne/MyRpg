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

game_asset_t *init_pause_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(PAUSE_BG_PATH, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

void back_home(game_t *game)
{
    game->scenes->prev = game->scenes->current;
    game->scenes->current = MAIN_MENU;
}

button_t **init_buttons_pause(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    float pos_x = 960 - 390 / 2;

    buttons[0] = create_button("Play", (sfVector2f) {pos_x ,500}, go_to_game);
    buttons[1] = create_button("Settings",(sfVector2f) {pos_x, 650},
                               go_to_settings);
    buttons[2] = create_button("Quit", (sfVector2f) {pos_x, 800}, quit_game);
    buttons[3] = create_button("Back home", (sfVector2f) {pos_x, 800}, back_home);
    buttons[4] = NULL;
    return buttons;
}

pause_t *init_pause(void)
{
    pause_t *scene = malloc(sizeof(main_menu_scenes_t));

    if (!scene)
        return NULL;
    scene->background = init_pause_background();
    scene->buttons = init_buttons_pause();
    return scene;
}
