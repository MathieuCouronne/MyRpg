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

static void init_icons(button_t **icons)
{
    float icons_pos = 1100 - 41 / 2;

    icons[0] = create_icon((sfVector2f) {icons_pos ,410},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[1] = create_icon((sfVector2f) {icons_pos ,470},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[2] = create_icon((sfVector2f) {icons_pos ,530},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[3] = create_icon((sfVector2f) {icons_pos ,590},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[4] = create_icon((sfVector2f) {icons_pos ,650},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[5] = create_icon((sfVector2f) {icons_pos ,710},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[6] = create_icon((sfVector2f) {icons_pos ,770},
        BUTTON_SETTINGS_PATH, go_to_prev);
    icons[7] = NULL;
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
