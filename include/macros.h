/*
** EPITECH PROJECT, 2021
** macros.h
** File description:
** my_rpg macros header file
*/

#ifndef RPG_MACROS_H
    #define RPG_MACROS_H

    #define WINDOW_NAME "MyRPG"
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define WINDOW_BITS 32
    #define LOADER_WINDOW_WIDTH 500
    #define LOADER_WINDOW_HEIGHT 600
    #define WINDOW_PADDING 350
    #define MAP_SCALE 2
    #define MAP_WIDTH 3840
    #define MAP_HEIGHT 3840
    #define DEFAULT_VIEW_X 2270
    #define DEFAULT_VIEW_Y 2030

    // Misc
    #define ASSETS_AMOUNT 37
    #define PLAYER_SCALE 1.15
    #define PLAYER_MOVEMENT 2.5
    #define QUEST_AMOUNT 3
    #define LAVA_AMOUNT 150

    // Sprites Pathes
    #define WARRIOR_PATH "./assets/images/characters/warrior.png"
    #define MAGE_PATH "./assets/images/characters/mage.png"
    #define DOGWARRIOR_PATH "./assets/images/characters/dogwarrior.png"
    #define ALBERT_PATH "./assets/images/characters/albert.png"
    #define CHIEF_PATH "./assets/images/characters/chief.png"
    #define TROLL_PATH "./assets/images/characters/troll.png"
    #define OGRE_PATH "./assets/images/characters/ogre.png"
    #define REVERSED_OGRE_PATH "./assets/images/fight/reversed_ogre.png"
    #define REVERSED_TROLL_PATH "./assets/images/fight/reversed_troll.png"
    #define REVERSED_DRAGON_PATH "./assets/images/fight/reversed_dragon.png"
    #define DRAGON_PATH "./assets/images/characters/dragon.png"
    #define SAVES_PATH "./assets/images/saves/save.png"
    #define BUTTON_PATH "./assets/images/main_menu/rectangle_button.png"
    #define HELP_PATH "./assets/images/main_menu/help.png"
    #define FIGHT_BG_PATH "./assets/images/fight/background.png"
    #define FIGHT_TOOLTIP_PATH "./assets/images/fight/tooltip.png"
    #define FIGHT_PLAYER_BAR_PATH "./assets/images/fight/player_bar.png"
    #define FIGHT_ENEMY_BAR_PATH "./assets/images/fight/enemy_bar.png"
    #define AREAS_PATH "./assets/images/game/areas.jpg"
    #define MAP_PATH "./assets/images/game/map.jpg"
    #define QUEST_BG_PATH "./assets/images/game/quest.png"
    #define MAIN_MENU_BG_PATH "./assets/images/main_menu/background.png"
    #define SETTINGS_BG_PATH "./assets/images/settings/settings.jpg"
    #define BUTTON_SETTINGS_PATH "./assets/images/settings/empty_icon.png"
    #define PAUSE_BG_PATH "./assets/images/pause/pause_scene.png"
    #define SAVES_EMPTY_PATH "./assets/images/saves/empty.png"
    #define SAVES_BACK_PATH "./assets/images/saves/back.png"
    #define HELP_BG_PATH "./assets/images/help/background.jpg"
    #define CREATION_BG_PATH "./assets/images/creation/champ_select.jpg"
    #define CREATION_PLUS_PATH "./assets/images/creation/plus_buttons.png"
    #define CREATION_LESS_PATH "./assets/images/creation/less.png"
    #define CREATION_ARROW_LEFT_PATH "./assets/images/creation/arrow_left.png"
    #define CREATION_ARROW_RIGHT_PATH "./assets/images/creation/arrow_right.png"
    #define CREATION_VALIDATE_PATH "./assets/images/creation/ok.png"
    #define LOADER_BAR_BG_PATH "./assets/images/loader/background.png"
    #define LOADER_BAR_PATH "./assets/images/loader/bar.png"
    #define LOADER_FILL_PATH "./assets/images/loader/fill.png"
    #define LEVEL_UP_PATH "./assets/images/game/level_up.png"
    #define VICTORY_PATH "./assets/images/fight/victory.png"
    #define DEFEAT_PATH "./assets/images/fight/defeat.png"
    #define CREDITS_BG_PATH "./assets/images/credits/background.png"

    // Sounds Pathes
    #define MAIN_THEME_PATH "./assets/sounds/hearthstone.ogg"
    #define WALK_PATH "./assets/sounds/Walk.ogg"
    #define CLIC_PATH "./assets/sounds/clic.ogg"

    // Inventory
    #define INVENTORY_PATH "./assets/images/inventory/inventory.png"
    #define BOOK_PATH "./assets/images/inventory/book.jpg"
    #define DRAGON_TAIL_PATH "./assets/images/inventory/dragon_tail.jpg"
    #define TROLL_FANG_PATH "./assets/images/inventory/troll_fang.jpg"

    // Fonts Pathes
    #define ARIAL_FONT_PATH "./assets/fonts/arial_black.ttf"

    // Config files
    #define CONFIG_FILE_PATH "./config/game.config"
    #define PLAYER1_FILE_PATH "./config/saves/player1.config"
    #define PLAYER2_FILE_PATH "./config/saves/player2.config"
    #define PLAYER3_FILE_PATH "./config/saves/player3.config"

    // Albert
    #define TOP_PADDING 9
    #define LEFT_PADDING 22
    #define ALBERT_WIDTH 38
    #define ALBERT_HEIGHT 66

#endif // RPG_MACROS_H
