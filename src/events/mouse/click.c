/*
** EPITECH PROJECT, 2021
** click.c
** File description:
** Game buttons click events handling
*/

#include "my_rpg.h"

bool handle_buttons_clicks(game_t *game, button_t **buttons)
{
    sfVector2i pos = {game->event.mouseButton.x, game->event.mouseButton.y};

    if (game->event.type != sfEvtMouseButtonPressed || !buttons)
        return false;
    for (unsigned short i = 0; buttons[i]; i++) {
        if (!is_pos_in_button(buttons[i], pos)) {
            continue;
        }
        sfSound_play(game->sounds->clic);
        buttons[i]->on_click(game);
        return true;
    }
    return false;
}

bool handle_slider_move(game_t *game)
{
    settings_t *settings = game->scenes->settings;
    sfVector2f position = sfCircleShape_getPosition(settings->slider);
    float volume = 0;

    if (game->event.type != sfEvtMouseMoved || !settings->slider_selected)
        return false;
    if (game->event.mouseMove.x < 795 ||
    game->event.mouseMove.x + 20 > 1125)
        return false;
    position.x = (float) game->event.mouseMove.x - 10;
    volume = ((float) game->event.mouseMove.x - 795) / 1125 * 100;
    sfCircleShape_setPosition(settings->slider, position);
    sfMusic_setVolume(game->sounds->menu, volume);
    return true;
}

bool handle_slider_click(game_t *game)
{
    settings_t *settings = game->scenes->settings;
    sfVector2f cursor = {game->event.mouseButton.x, game->event.mouseButton.y};
    sfVector2f position = sfCircleShape_getPosition(settings->slider);
    float radius = sfCircleShape_getRadius(settings->slider);

    if (game->event.type == sfEvtMouseButtonReleased) {
        settings->slider_selected = false;
        return true;
    } else if (game->event.type != sfEvtMouseButtonPressed)
        return false;
    position.x += radius;
    position.y += radius;
    if ((cursor.x >= position.x - radius && cursor.x <= position.x + radius)
        && (cursor.y >= position.y - radius &&
            cursor.y <= position.y + radius)) {
        settings->slider_selected = true;
        return true;
    }
    return false;
}
