/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include "structs.h"
#include "menu.h"
#include <SFML/Audio.h>
#include "my_rpg.h"

sound_t *menu_music(sound_t *music)
{
    music->music = sfMusic_createFromFile("./assets/sound/Hearthstone.ogg");

    if (!music->music)
        return NULL;
    sfMusic_play(music->music);
    return music;
}
