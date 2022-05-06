/*
** EPITECH PROJECT, 2021
** quests.h
** File description:
** Initialize quests
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "menu.h"
#include "enum.h"
#include "character.h"
#include "macros.h"
#include "structs.h"

static quest_t *create_first_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->id = 0;
    quest->xp = 15;
    quest->name = "Quest 1";
    quest->launched = false;
    quest->done = false;
    quest->required = malloc(sizeof(slot_t *) * 2);
    quest->required[0] = malloc(sizeof(slot_t));
    quest->required[0]->id = FANG;
    quest->required[0]->quantity = 5;
    quest->required[0]->pos.x = 0;
    quest->required[0]->pos.y = 5;
    quest->required[1] = NULL;
    return quest;
}

quests_t *init_quests(void)
{
    quests_t *quests = malloc(sizeof(quests_t));

    if (!quests)
        return NULL;
    quests->quests = malloc(sizeof(quest_t *) * (QUEST_AMOUNT + 1));
    quests->quests[0] = create_first_quest();
    quests->quests[1] = NULL;
    return quests;
}
