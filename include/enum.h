/*
** EPITECH PROJECT, 2021
** enum.h
** File description:
** my_rpg enum
*/

#ifndef RPG_ENUM_H
    #define RPG_ENUM_H

typedef enum {
    ACTIVE, INACTIVE, HOVER
} button_state;

typedef enum {
    MAIN_MENU, MAIN_GAME, FIGHT, CREATION, SETTINGS, SAVES, PAUSE,
    INVENTORY
} scenes;

#endif // RPG_ENUM_H
