/*
** EPITECH PROJECT, 2021
** macros.h
** File description:
** my_rpg macros header file
*/

#ifndef RPG_MACROS_H
    #define RPG_MACROS_H

    // Functions
    #define ABS(x) (x < 0) ? -x : x

    #define WINDOW_NAME "MyRPG"
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define WINDOW_BITS 32
    #define WINDOW_PADDING 350
    #define MAP_WIDTH 3200
    #define MAP_HEIGHT 3200

    // Misc
    #define PLAYER_SCALE 1.15
    #define PLAYER_MOVEMENT 2.5

    // Sprites Pathes
    #define WARRIOR_PATH "./assets/images/characters/warrior.png"
    #define MAGE_PATH "./assets/images/characters/mage.png"
    #define DOGWARRIOR_PATH "./assets/images/characters/dogwarrior.png"
    #define ALBERT_PATH "./assets/images/characters/albert.png"
    #define CHIEF_PATH "./assets/images/characters/chief.png"
    #define SAVES_PATH "./assets/images/saves/save.png"
    #define INVENTORY_PATH "./assets/images/inventory/inventory.png"
    #define ENEMY_PATH "./assets/images/characters/enemy.png"
    #define BUTTON_PATH "./assets/images/main_menu/rectangle_button.png"
    #define CHEST_PATH "./assets/images/misc/chest.png"
    #define FIGHT_BG_PATH "./assets/images/fight/background.png"
    #define FIGHT_TOOLTIP_PATH "./assets/images/fight/tooltip.png"
    #define FIGHT_HP_BAR_PATH "./assets/images/fight/hp_bar.png"
    #define AREAS_PATH "./assets/images/maps/areas.jpg"
    #define MAP_PATH "./assets/images/maps/map.png"
    #define MAIN_MENU_BG_PATH "./assets/images/main_menu/background.png"
    #define SETTINGS_BG_PATH "./assets/images/settings/background.jpg"
    #define BUTTON_SETTINGS_PATH "./assets/images/settings/empty_icon.png"
    #define PAUSE_BG_PATH "./assets/images/pause/pause_scene.png"
    #define SAVES_EMPTY_PATH "./assets/images/saves/empty.png"
    #define SAVES_BACK_PATH "./assets/images/saves/back.png"

    // Sounds Pathes
    #define MAIN_THEME_PATH "./assets/sounds/hearthstone.ogg"

    // Fonts Pathes
    #define ARIAL_FONT_PATH "./assets/fonts/arial_black.ttf"

    // Config files
    #define CONFIG_FILE_PATH "./config/game.config"
    #define PLAYER1_FILE_PATH "./config/saves/player1.config"
    #define PLAYER2_FILE_PATH "./config/saves/player3.config"
    #define PLAYER3_FILE_PATH "./config/saves/player3.config"

    // Albert
    #define TOP_PADDING 9
    #define LEFT_PADDING 22
    #define ALBERT_WIDTH 38
    #define ALBERT_HEIGHT 66


#endif // RPG_MACROS_H
