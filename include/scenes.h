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

main_menu_scenes_t *init_main_menu(void);
main_game_t *init_main_game(game_t *game);

#endif
