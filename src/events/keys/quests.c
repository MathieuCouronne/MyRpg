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
        if (!current->messages[current->step_index + 1])
            quests->current++;
        else
            current->step_index++;
        current->msg_index = 0;
        quests->speaking = false;
        return true;
    }
    msg = (char *) current->messages[current->step_index][++current->msg_index];
    sfText_setString(game->quests->text, msg);
    return true;
}

bool handle_quests_keys(game_t *game)
{
    if (handle_quest_dialog(game) || handle_quest_next_step(game))
        return true;
    return false;
}
