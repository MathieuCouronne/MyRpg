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

game_asset_t *init_pause_background(game_t *game)
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
    float pos_x = 960 - 273 / 2;

    buttons[0] = create_button("Play", (sfVector2f) {pos_x ,370}, go_to_game,
    (sfVector2f) {.7f, .7f});
    buttons[1] = create_button("Settings",(sfVector2f) {pos_x, 470},
        go_to_settings, (sfVector2f) {.7f, .7f});
    buttons[2] = create_button("Home", (sfVector2f) {pos_x, 570}, back_home,
    (sfVector2f) {.7f, .7f});
    buttons[3] = create_button("Quit", (sfVector2f) {pos_x, 670},
        quit_game, (sfVector2f) {.7f, .7f});
    buttons[4] = NULL;
    return buttons;
}

pause_t *init_pause(game_t *game)
{
    pause_t *scene = malloc(sizeof(pause_t));

    if (!scene)
        return NULL;
    scene->background = init_pause_background(game);
    scene->buttons = init_buttons_pause();
    return scene;
}
