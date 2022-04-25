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

sound_t *menu_music()
{
    sound_t *music = malloc(sizeof(sound_t));

    if (!music)
        return NULL;
    music->music = sfMusic_createFromFile("./assets/sound/Hearthstone.ogg");
    sfMusic_play(music->music);
    return music;
}
