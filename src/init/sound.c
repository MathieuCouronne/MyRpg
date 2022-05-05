/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

void play_music(sfMusic *sounds)
{
    sfMusic_play(sounds);
}

sounds_t *menu_music(config_t *config)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->chest = sfMusic_createFromFile(OPEN_CHEST_PATH);
    sounds->menu = sfMusic_createFromFile(MAIN_THEME_PATH);
    if (!sounds->menu)
        return NULL;
    sfMusic_play(sounds->menu);
    sfMusic_setVolume(sounds->menu, config->volume);
    return sounds;
}
