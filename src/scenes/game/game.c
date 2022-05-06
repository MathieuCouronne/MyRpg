/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_fight(game_t *game)
{
    if (detect_enemies(game)) {
        game->scenes->prev = game->scenes->current;
        game->scenes->current = FIGHT;
    }
}

static void event_handling(game_t *game)
{
    handle_arrow_keys(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        handle_game_change_scenes(game);
        if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyK) {
            sfRenderWindow_setView(game->window, sfRenderWindow_getDefaultView(game->window));
            event_fight(game);
        }
    }
}

bool display_main_game(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_game_t *main_game = NULL;

    if (!game || !game->window || !game->scenes || !game->scenes->main_menu ||
        !game->scenes->main_menu->buttons)
        return false;
    window = game->window;
    main_game = game->scenes->game_scene;
    sfRenderWindow_setView(window, game->view);
    sfRenderWindow_drawSprite(window, main_game->map->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, main_game->chest->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, main_game->chief->sprite, NULL);
    sfRenderWindow_drawSprite(window, main_game->albert->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprite, NULL);
    event_handling(game);
    return true;
}
