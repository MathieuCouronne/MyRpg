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
typedef struct main_game_s main_game_t;
typedef struct main_creation_scenes_s main_creation_scenes_t;
typedef struct fight_s fight_t;
typedef struct enemy_s enemy_t;
typedef struct npc_s npc_t;
typedef struct text_s text_t;
typedef struct settings_s settings_t;
typedef struct loader_s loader_t;
typedef struct key_controller_s key_controller_t;
typedef struct pause_s pause_t;
typedef struct inventory_sprite_s inventory_sprite_t;
typedef struct scene_saves_s scene_saves_t;
typedef struct quest_s quest_t;
typedef struct quests_s quests_t;
typedef struct thread_params_s thread_params_t;
typedef struct stats_scene_s stats_scene_t;

struct sounds_s {
    sfMusic *menu;
    sfMusic *main_theme;
    sfMusic *chest;
    sfSound *clic;
    sfSoundBuffer *buffer;
};

struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfImage *collisions;
    game_asset_t **characters;
    sfView *view;
    scenes_t *scenes;
    sounds_t *sounds;
    player_t *player;
    enemy_t **enemy;
    config_t *config;
    character_t **saves;
    stats_t *stats;
    quests_t *quests;
    unsigned short current;
    unsigned int enemy_id;
};

struct game_asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    sfVector2f pos;
};

struct button_s {
    game_asset_t *asset;
    sfText *text;
    sfFont *font;
    void (*on_click) (game_t *game);
    bool hover;
    bool select;
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
    stats_scene_t *stats;
    inventory_sprite_t *inventory;
};

struct main_game_s {
    game_asset_t *map;
    npc_t **npc;
    chest_t *chest;
    sfClock *level_up_clock;
    sfCircleShape **lava;
    game_asset_t *level_up_sprite;
    bool level_up;
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
    sfText **text;
    sfText ***stat;
    sfFont *font;
    int **stats;
    int class;
    int *unspent;
    sfText **unspent_text;
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
    sfColor color;
    char *name;
    int dps;
    int hp;
    unsigned int max_hp;
};

struct npc_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f position;
    sfTexture *texture;
    sfColor color;
};

struct fight_s {
    game_asset_t *background_fight;
    game_asset_t *text_bar;
    game_asset_t *player_bar;
    game_asset_t *enemy_bar;
    sfText *text_player_hp;
    sfText *text_enemy_hp;
    sfFont *font;
    character_t *character;
    player_t **characters;
    button_t **buttons;
    player_t *player;
    enemy_t **enemy;
    game_t *game;
};

struct settings_s {
    game_asset_t *background;
    button_t **buttons;
    button_t **icons;
    sfText **keys;
    sfFont *font;
    unsigned int current;
};

struct loader_s {
    sfRenderWindow *window;
    sfEvent event;
    game_asset_t *background;
    game_asset_t *bar;
    game_asset_t *fill;
};

struct pause_s {
    game_asset_t *background;
    button_t **buttons;
    sfView *view;
};

struct inventory_sprite_s {
    game_asset_t *background;
    game_asset_t **loot;
    button_t **buttons;
    sfVector2f pos;
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
    game_asset_t *background;
    button_t **buttons;
    game_asset_t **character;
};

struct thread_params_s {
    game_t *game;
    int *loaded;
};

struct quests_s {
    unsigned int current;
    game_asset_t *asset;
    sfText *text;
    quest_t **quests;
    bool speaking;
};

struct quest_s {
    bool started;
    bool done;
    unsigned int id;
    unsigned int xp;
    unsigned int npc_id;
    char *name;
    slot_t **required;
    slot_t **rewards;
    unsigned int step_index;
    unsigned int msg_index;
    const char ***messages;
};

struct stats_scene_s {
    game_asset_t *background;
    button_t **buttons;
    sfText *text;
    sfText **stat;
    sfFont *font;
    int *stats;
    int unspent;
    sfText *unspent_text;
};

#endif
