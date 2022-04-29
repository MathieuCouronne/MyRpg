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
#include "enum.h"

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct config_value_s config_value_t;
typedef struct config_s config_t;
typedef struct scenes_s scenes_t;
typedef struct sounds_s sounds_t;
typedef struct game_s game_t;
typedef struct game_asset_s game_asset_t;
typedef struct event_controller_s event_controller_t;
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
typedef struct text_s text_t;
typedef struct settings_s settings_t;


struct sounds_s {
    sfMusic *menu;
    sfMusic *main_theme;
};

struct config_value_s {
    char *key;
    char *value;
};

struct config_s {
    config_value_t *assets_loaded;
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
    chest_t *chest;
    config_t *config;
};

struct game_asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfVector2f pos;
    float scaling;
};

struct button_s {
    game_asset_t *asset;
    sfText *text;
    button_state state;
    sfFont *font;
    void (*on_click) (game_t *game);
};

struct main_menu_scenes_s {
    game_asset_t *background;
    button_t **buttons;
};

struct event_controller_s {
    sfEventType type;
    game_asset_t *background;
    button_t **buttons;
    void (*fn) (game_t *game, sfEvent *event);
};

struct scenes_s {
    scenes current;
    scenes prev;
    main_menu_scenes_t *main_menu;
    main_game_t *game_scene;
    main_creation_scenes_t *creation_menu;
    settings_t *settings;
    fight_t *fight;
};

struct game_scene_s {
    game_asset_t *map;
    sfView *view;
};

struct main_game_s {
    game_asset_t *map;
};

struct player_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f *position;
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

struct menu_creation_s {
    button_t *confirm;
};

struct main_creation_scenes_s {
    game_asset_t *background;
    menu_creation_t *buttons;
};

struct text_s {
    sfText *text;
    sfFont *font;
};

struct enemy_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f position;
    sfTexture *texture;
    char *name;
    unsigned int dps;
    unsigned int hp;
};

struct fight_s {
    game_asset_t *background_fight;
    game_asset_t *text_bar;
    game_asset_t *hp_bar;
    player_t *player;
    enemy_t *enemy;
};

struct settings_s {
    game_asset_t *background;
    game_asset_t *settings;
    button_t **buttons;
};
#endif
