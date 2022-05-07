/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static bool check_key(game_t *game, sfKeyCode key, sfKeyCode *keybinds[])
{
    for (size_t i = 0; i < 7; i++) {
        if (*keybinds[i] == key || key == sfKeyK || key == sfKeyT)
            return true;
    }
    return false;
}

static void event_handling(game_t *game, sfKeyCode *keybinds[])
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->settings->buttons);
        default_event_handling(game, game->scenes->settings->icons);
        if (game->event.type == sfEvtKeyPressed && check_bool(game) == 1) {
            if (check_key(game, game->event.key.code, keybinds))
                return;
            game->scenes->settings->icons
            [game->scenes->settings->current]->select = false;
            *keybinds[game->scenes->settings->current] = game->event.key.code;
            sfText_setString(game->scenes->settings->keys
            [game->scenes->settings->current],
            char_from_key(*keybinds[game->scenes->settings->current]));
        }
    }
}

static void display(settings_t *settings,
    sfRenderWindow *window, button_t **icons, button_t **buttons)
{
    sfRenderWindow_drawSprite(window, settings->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawText(window, buttons[0]->text, NULL);
    for (size_t i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(window, icons[i]->asset->sprite, NULL);
    for (size_t i = 0; i < 7; i++) {
        if (settings->icons[i]->select == true)
            continue;
        sfRenderWindow_drawText(window, settings->keys[i], NULL);
    }
}

bool display_settings(game_t *game)
{
    sfRenderWindow *window = NULL;
    settings_t *settings = NULL;
    button_t **buttons = NULL;
    button_t **icons = NULL;
    sfKeyCode *keybinds[] = {
        &game->config->keys->inventory, &game->config->keys->interact,
        &game->config->keys->pause, &game->config->keys->left,
        &game->config->keys->right, &game->config->keys->up,
        &game->config->keys->down
    };

    if (!game || !game->window || !game->scenes || !game->scenes->settings)
        return false;
    event_handling(game, keybinds);
    window = game->window;
    settings = game->scenes->settings;
    buttons = settings->buttons;
    icons = settings->icons;
    display(settings, window, icons, buttons);
    return true;
}
