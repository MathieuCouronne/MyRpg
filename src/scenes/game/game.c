/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static bool event_fight(game_t *game)
{
    if (detect_enemies(game)) {
        sfRenderWindow_setView(game->window,
            sfRenderWindow_getDefaultView(game->window));
        game->scenes->prev = game->scenes->current;
        game->scenes->current = FIGHT;
        create_text_enemy(game->enemy[game->enemy_id], game->scenes->fight);
        create_text_player(game->saves[game->current], game->scenes->fight);
        return true;
    }
    return false;
}

static bool event_handling(game_t *game)
{
    handle_arrow_keys(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        handle_game_change_scenes(game);
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyK && event_fight(game))
            return true;
    }
    return false;
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
    sfRenderWindow_drawSprite(window, main_game->chest->sprite, NULL);
    for (unsigned int i = 0; main_game->npc[i]; i++)
        sfRenderWindow_drawSprite(window, main_game->npc[i]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->sprite, NULL);
    display_quest(game);
    if (event_handling(game))
        return true;
    return true;
}
