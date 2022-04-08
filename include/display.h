/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef SCENES_H_
    #define SCENES_H_

typedef struct main_menu_scenes_s {

} main_menu_scenes_t;

typedef struct scenes_s {
    main_menu_scenes_t *main_menu;
    // TODO: add buttons
} scenes_t;

main_menu_scenes_t *init_main_menu(void);

#endif
