/*
** EPITECH PROJECT, 2021
** quests.c
** File description:
** Game keys quests event handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static bool handle_quest_dialog(game_t *game)
{
    quest_t *current = game->quests->quests[game->quests->current];
    char *msg = NULL;

    if (!current || game->quests->speaking ||
    game->event.key.code != game->config->keys->interact)
        return false;
    transform_dialog(game);
    if (!current->started && !game->quests->speaking) {
        current->step_index = 0;
        current->started = true;
    } else if (current->started &&
    !is_quest_valid(game->saves[game->current]->inventory, current->required))
        current->step_index = 2;
    else
        current->step_index = 1;
    current->msg_index = 0;
    game->quests->speaking = true;
    msg = (char *) current->messages[current->step_index][current->msg_index];
    sfText_setString(game->quests->text, msg);
    return true;
}

static bool handle_quest_next_step(game_t *game)
{
    quests_t *quests = game->quests;
    quest_t *current = quests->quests[quests->current];
    char *msg = NULL;

    if (!current || game->event.key.code != sfKeySpace || !quests->speaking ||
        !current->messages[current->step_index])
        return false;
    if (!current->messages[current->step_index][current->msg_index + 1]) {
        quests->speaking = false;
        if (current->step_index == 1)
            finish_quest(game);
        return true;
    }
    current->msg_index++;
    msg = (char *) current->messages[current->step_index][current->msg_index];
    sfText_setString(game->quests->text, msg);
    return true;
}

static void get_matching_npc(game_t *game, sfColor color, unsigned int i)
{
    for (unsigned int j = 0; game->scenes->game_scene->npc[j]; j++) {
        if (!color_cmp(color, game->scenes->game_scene->npc[j]->color) ||
            game->quests->quests[i]->npc_id != j || i != game->quests->current)
            continue;
        handle_quest_dialog(game);
        handle_quest_next_step(game);
    }
}

bool handle_quests_keys(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->sprite);
    sfFloatRect size = sfSprite_getGlobalBounds(game->player->sprite);
    sfColor color = {0};

    if (game->event.type != sfEvtKeyPressed ||
    (game->event.type == sfEvtKeyPressed &&
    (game->event.key.code != game->config->keys->interact &&
    game->event.key.code != sfKeySpace)))
        return false;
    pos.x += size.width / 2;
    pos.y += size.height;
    color = get_pixel_at_pos(game, pos);
    for (unsigned int i = 0; game->quests->quests[i]; i++) {
        if (game->quests->quests[i]->done)
            continue;
        get_matching_npc(game, color, i);
    }
    return false;
}
