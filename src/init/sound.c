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

static void play_musics(sound_t *sounds)
{
    sfMusic_play(sounds->main_theme);
}

sound_t *menu_music(void)
{
    sound_t *sounds = malloc(sizeof(sound_t));

    if (!sounds)
        return NULL;
    sounds->main_theme = sfMusic_createFromFile("./assets/sound/Hearthstone.ogg");
    if (!sounds->main_theme)
        return NULL;
    play_musics(sounds);
    return sounds;
}
