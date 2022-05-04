/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "menu.h"
#include "enum.h"
#include "character.h"

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct config_s config_t;
typedef struct scenes_s scenes_t;
typedef struct sounds_s sounds_t;
typedef struct game_s game_t;
typedef struct game_asset_s game_asset_t;
typedef struct button_s button_t;
typedef struct main_menu_scenes_s main_menu_scenes_t;
typedef struct chest_s chest_t;
typedef struct player_s player_t;
typedef struct game_scene_s game_scene_t;
typedef struct main_game_s main_game_t;
typedef struct menu_creation_s menu_creation_t;
typedef struct main_creation_scenes_s main_creation_scenes_t;
typedef struct fight_s fight_t;
typedef struct enemy_s enemy_t;
typedef struct pnj_s npc_t;
typedef struct text_s text_t;
typedef struct settings_s settings_t;
typedef struct key_controller_s key_controller_t;
typedef struct pause_s pause_t;
typedef struct inventory_sprite_s inventory_sprite_t;
typedef struct scene_saves_s scene_saves_t;
typedef struct attack_s attack_t;

struct sounds_s {
    sfMusic *menu;
    sfMusic *main_theme;
};

struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfImage *collisions;
    sfView *view;
    scenes_t *scenes;
    sounds_t *sounds;
    player_t *player;
    enemy_t *enemy;
    npc_t *albert;
    npc_t *chief;
    chest_t *chest;
    config_t *config;
    character_t **saves;
};

struct game_asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    sfVector2f pos;
    float scaling;
};

struct button_s {
    game_asset_t *asset;
    sfText *text;
    button_state state;
    sfFont *font;
    void (*on_click) (game_t *game);
    bool hover;
};

struct main_menu_scenes_s {
    game_asset_t *background;
    button_t **buttons;
};

struct scenes_s {
    scenes current;
    scenes prev;
    main_menu_scenes_t *main_menu;
    main_game_t *game_scene;
    main_creation_scenes_t *creation_menu;
    settings_t *settings;
    scene_saves_t *saves;
    fight_t *fight;
    pause_t *pause;
    inventory_sprite_t *inventory;
};

struct main_game_s {
    game_asset_t *map;
};

struct player_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f *position;
    sfVector2f *relative_pos;
    sfTexture *texture;
    sfClock *clock;
};

struct chest_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f position;
    sfTexture *texture;
    sfClock *clock;
};

struct main_creation_scenes_s {
    game_asset_t *background;
    button_t **buttons;
};

struct text_s {
    sfText *text;
    sfFont *font;
};

struct enemy_s {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    sfTexture *texture;
    char *name;
    unsigned int dps;
    unsigned int hp;
    unsigned int max_hp;
};

struct pnj_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f position;
    sfVector2f *relative_pos;
    sfTexture *texture;
};

struct fight_s {
    game_asset_t *background_fight;
    game_asset_t *text_bar;
    game_asset_t *hp_bar;
    button_t **buttons;
    player_t *player;
    enemy_t *enemy;
};

struct settings_s {
    game_asset_t *background;
    button_t **buttons;
    button_t **icons;
};

struct pause_s {
    game_asset_t *background;
    button_t **buttons;
    sfView *view;
};

struct inventory_sprite_s {
    game_asset_t *background;
    button_t **buttons;
    sfView *view;
};

struct key_controller_s {
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode inventory;
    sfKeyCode pause;
    sfKeyCode interact;
};

struct config_s {
    unsigned int assets_loaded;
    unsigned int volume;
    key_controller_t *keys;
};

struct scene_saves_s {
    game_asset_t **background;
    button_t **buttons;
    game_asset_t **character;
    button_t **icons;
};

struct attack_s {
    char const *name;
    unsigned int dmg;
};

#endif
