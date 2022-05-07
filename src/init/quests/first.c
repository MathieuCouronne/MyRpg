/*
** EPITECH PROJECT, 2021
** first.c
** File description:
** Initialize first quest
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "enum.h"
#include "character.h"
#include "structs.h"

static const char *welcome[3] = {
    "Hey lad ! Come here! I need help... " \
    "I'm getting old, as you\ncan see around you, some trolls took" \
    " control of the western\npart of the village.",
    "I would be grateful if you could please get rid of them and\n" \
    "bring me 5 of their fangs so I can brew some potions please?",
    NULL
};

static const char *valid[5] = {
    "- Oh here you are already ! Have you done what I asked?",
    "......",
    "I can see you collected thoses fangs! Thank you very much" \
    "\nfor your help... ",
    NULL
};

static const char *invalid[5] = {
    "- Oh here you are already! Have you done what I asked?",
    "......",
    "I can see you didn't collected enough fangs!",
    NULL
};

static char const **messages[4] = {
    welcome, valid, invalid, NULL
};

static slot_t **init_required_items(void)
{
    slot_t **required = malloc(sizeof(slot_t *) * 2);

    if (!required)
        return NULL;
    required[0] = malloc(sizeof(slot_t));
    if (!required[0])
        return NULL;
    required[0]->id = FANG;
    required[0]->quantity = 5;
    required[0]->pos.x = 0;
    required[0]->pos.y = 0;
    required[1] = NULL;
    return required;
}

quest_t *create_first_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->id = 0;
    quest->xp = 15;
    quest->name = "Get the fangs.";
    quest->started = false;
    quest->done = false;
    quest->step_index = 0;
    quest->msg_index = 0;
    quest->messages = messages;
    quest->required = init_required_items();
    quest->npc_id = 0;
    return quest;
}
