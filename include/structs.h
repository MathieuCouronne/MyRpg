/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "menu.h"
#include "idk.h"
#include "game.h"
#include "fight.h"
#include "scenes.h"

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct sounds_s {
    sfMusic *menu;
    sfMusic *main_theme;
} sounds_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfImage *collisions;
    sfView *view;
    scenes_t *scenes;
    sounds_t *sounds;
    player_t *player;
    enemy_t *enemy;
    chest_t *chest;
} game_t;

typedef struct event_controller_s {
    sfEventType type;
    void (*fn) (game_t *game, sfEvent *event);
} event_controller_t;

#endif
