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

static void play_musics(sounds_t *sounds)
{
    sfMusic_play(sounds->main_theme);
}

sounds_t *menu_music(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->main_theme = sfMusic_createFromFile("./assets/sound/Hearthstone.ogg");
    if (!sounds->main_theme)
        return NULL;
    play_musics(sounds);
    return sounds;
}
