/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    handle_arrow_keys(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        handle_game_change_scenes(game);
    }
}

static void display_quest(game_t *game)
{
    if (!game->quests->speaking || !game->quests->text)
        return;
    sfRenderWindow_drawSprite(game->window, game->quests->asset->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->quests->text, NULL);
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
    display_quest(game);
    event_handling(game);
    return true;
}
