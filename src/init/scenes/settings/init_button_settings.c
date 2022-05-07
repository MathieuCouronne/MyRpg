/*
** EPITECH PROJECT, 2021
** init_button_settings.c
** File description:
** Init buttons for settings scene
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

extern const char *KEYS[29];

extern const sfKeyCode KEY_CODES[29];


static void init_icons(button_t **icons)
{
    float icons_pos = 1100 - 41 / 2;

    icons[0] = create_icon((sfVector2f) {icons_pos ,410},
        BUTTON_SETTINGS_PATH, change_inventory);
    icons[1] = create_icon((sfVector2f) {icons_pos ,470},
        BUTTON_SETTINGS_PATH, change_interact);
    icons[2] = create_icon((sfVector2f) {icons_pos ,530},
        BUTTON_SETTINGS_PATH, change_pause);
    icons[3] = create_icon((sfVector2f) {icons_pos ,590},
        BUTTON_SETTINGS_PATH, change_left);
    icons[4] = create_icon((sfVector2f) {icons_pos ,650},
        BUTTON_SETTINGS_PATH, change_right);
    icons[5] = create_icon((sfVector2f) {icons_pos ,710},
        BUTTON_SETTINGS_PATH, change_up);
    icons[6] = create_icon((sfVector2f) {icons_pos ,770},
        BUTTON_SETTINGS_PATH, change_down);
    icons[7] = NULL;
}

char *char_from_key(sfKeyCode key)
{
    for (size_t i = 0; i < 28; i++) {
        if (key == KEY_CODES[i])
            return KEYS[i];
    }
    return 0;
}

static void set_parameters(sfText *text, sfFont *font)
{
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
}

sfText **init_keybinds_text(game_t *game , sfFont *font)
{
    key_controller_t *keys = game->config->keys;
    sfText **text = malloc(sizeof(sfText *) * 8);
    float shift[7] = {430, 490, 550, 610, 670, 730, 790};
    sfKeyCode keybinds[] = {
        keys->inventory, keys->interact, keys->pause, keys->left,
        keys->right, keys->up, keys->down
    };

    for (size_t i = 0; i < 7; i++) {
        text[i] = sfText_create();
        if (!text[i])
            return NULL;
        sfText_setString(text[i], char_from_key(keybinds[i]));
        set_parameters(text[i], font);
        sfText_setPosition(text[i], (sfVector2f) {1090, shift[i]});
    }
    return text;
}

button_t **init_icons_settings(void)
{
    button_t **icons = malloc(sizeof(button_t *) * 8);

    if (!icons)
        return NULL;
    init_icons(icons);
    for (size_t i = 0; i < 7; i++)
        if (!icons[i])
            return NULL;
    return icons;
}
