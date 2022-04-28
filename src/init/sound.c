/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"

void play_music(sfMusic *sounds)
{
    sfMusic_play(sounds);
}

sounds_t *menu_music(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->menu = sfMusic_createFromFile("./assets/sound/hearthstone.ogg");
    if (!sounds->menu)
        return NULL;
    return sounds;
}
