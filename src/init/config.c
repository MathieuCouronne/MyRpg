/*
** EPITECH PROJECT, 2022
** read.c
** File description:
** Read config file
*/

#include "my_rpg.h"
#include "character.h"

config_t *init_config(void)
{
    config_t *config = malloc(sizeof(config_t));

    if (!config)
        return NULL;
    config->keys = malloc(sizeof(key_controller_t));
    if (!config->keys)
        return NULL;
    config->assets_loaded = false;
    config->volume = 50;
    config->keys->up = sfKeyZ;
    config->keys->left = sfKeyQ;
    config->keys->down = sfKeyS;
    config->keys->right = sfKeyD;
    config->keys->pause = sfKeyEscape;
    config->keys->interact = sfKeyF;
    config->keys->inventory = sfKeyI;
    return config;
}