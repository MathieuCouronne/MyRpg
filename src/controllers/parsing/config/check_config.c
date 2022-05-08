/*
** EPITECH PROJECT, 2022
** check_config.c
** File description:
** check_config
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

extern const sfKeyCode KEY_CODES[29];

static bool is_key_valid(unsigned int value)
{
    for (size_t i = 0; i < 29; i++) {
        if (value == (unsigned int) KEY_CODES[i])
            return true;
    }
    return false;
}

static bool check_config_key(config_t *config)
{
    sfKeyCode keybinds[] = {
        config->keys->inventory, config->keys->interact, config->keys->pause,
        config->keys->left, config->keys->right, config->keys->up,
        config->keys->down
    };

    for (size_t y = 0; y < 7; y++) {
        if (!is_key_valid(keybinds[y]))
            return false;
    }
    return true;
}

bool check_config(config_t *config)
{
    if (config->assets_loaded > 1 || config->volume > 100 ||
    !check_config_key(config))
        return false;
    return true;
}
