/*
** EPITECH PROJECT, 2021
** enum.h
** File description:
** my_rpg enum
*/

#ifndef RPG_ENUM_H
    #define RPG_ENUM_H

typedef enum {
    MAIN_MENU, MAIN_GAME, FIGHT, CREATION, SETTINGS, SAVES, PAUSE,
    INVENTORY, STATS, CREDITS
} scenes;

typedef enum {
    EMPTY = -1, FANG, BOOK, DRAGON_TAIL,
} items;

#endif // RPG_ENUM_H
