/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include "fight.h"
#include "menu.h"
#include "game.h"
#include "menu_creation.h"

#ifndef SCENES_H_
    #define SCENES_H_

typedef struct scenes_s {
    scenes current;
    main_menu_scenes_t *main_menu;
    main_game_t *game_scene;
    main_creation_scenes_t *creation_menu;
    fight_t *fight;
} scenes_t;

#endif
