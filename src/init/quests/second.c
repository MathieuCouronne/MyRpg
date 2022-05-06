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
    "But I have something else to ask...",
    "I accidentally dropped my book behind the Church...\n" \
    "Could you bring it to me ? I'm kind of scared to go there...\n" \
    "Who knows what could happen to an old man like me...",
    NULL
};

static const char *valid[4] = {
    "Thank you young man! I really appreciate what you've done\n" \
    "for me! Now that I think about it, I think you could give a hand\n" \
    "near the burnt land, go there abd you'll meet a friend of mine.",
    "Everybody here calls him Uo, you should also ask him\n" \
    "for some food, he is a really good chief, but... don't be in a\n" \
    " hurry... He is pretty slow at cooking...\n",
    "Anyways! You're free to go! Thank you again my friend.",
    NULL
};

static char const **messages[3] = {
    welcome, valid, NULL
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

quest_t *create_second_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->id = 0;
    quest->xp = 15;
    quest->name = "Get the books";
    quest->started = false;
    quest->done = false;
    quest->step_index = 0;
    quest->msg_index = 0;
    quest->messages = messages;
    quest->required = init_required_items();
    return quest;
}
