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
    quests_t *quests = game->quests;
    quest_t *current = quests->quests[quests->current];
    char *msg = NULL;

    if (!current || game->event.key.code != game->config->keys->interact)
        return false;
    if (!current->started && !game->quests->speaking) {
        transform_dialog(game);
        transform_dialog_txt(game, game->quests->text);
        game->quests->speaking = true;
    }
    current->started = false;
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
        if (!current->messages[current->step_index + 1]) {
            quests->current++;
            current->done = true;
        } else
            current->step_index++;
        current->msg_index = 0;
        quests->speaking = false;
        return true;
    }
    msg = (char *) current->messages[current->step_index][++current->msg_index];
    sfText_setString(game->quests->text, msg);
    return true;
}

static void get_matching_npc(game_t *game, sfColor color, unsigned int i)
{
    for (unsigned int j = 0; game->scenes->game_scene->npc[j]; j++) {
        if (!color_cmp(color, game->scenes->game_scene->npc[j]->color) ||
            game->quests->quests[i]->npc_id != j)
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

    if (game->event.type != sfEvtKeyPressed)
        return false;
    pos.x += size.width / 2;
    pos.y += size.height / 2;
    color = get_pixel_at_pos(game, pos);
    for (unsigned int i = 0; game->quests->quests[i]; i++) {
        if (game->quests->quests[i]->done)
            continue;
        get_matching_npc(game, color, i);
    }
    return false;
}
