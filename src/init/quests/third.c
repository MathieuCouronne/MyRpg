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

static const char *welcome[7] = {
    "You: Hello there! Are you Chief Uo?",
    "Uo: Yes I am! Have you heard about my cooking abilities?",
    "You: Hum... yes. I heard only good things about you and I...",
    "Uo: Okay! Stop talking I don't care! I need you to get me a very\n" \
        "special ingredient for a new recipe, I'm sure you'll love it",
    "You: Oh... Okay?",
    "Uo: You'll have to adventure to the deepest part of the\nburnt land, " \
        "you'll understand what I want you to get...",
    NULL
};

static const char *valid[8] = {
    "Uo: Oh look who's there!\nMy friend... did you get my secret ingredient ?",
    "....",
    "Give me that! Give me a few minutes, " \
        "I need to cook,\nyou'll have to taste it !",
    "(2 hours later)",
    "Uo: And voila! Here is my new creation,\na delicious taco, taste it!",
    "...........",
    "You: Wow! You're a real Chief Pal Uo!",
    NULL
};

static const char *invalid[4] = {
    "Hey wassup ?",
    ".....",
    "What the heck are you doing!?\nGO AND KILL THAT FREAKING DRAGON!!!!",
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
    required[0]->id = DRAGON_TAIL;
    required[0]->quantity = 1;
    required[0]->pos.x = 0;
    required[0]->pos.y = 0;
    required[1] = NULL;
    return required;
}

quest_t *create_third_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->id = 2;
    quest->xp = 120;
    quest->name = "Get the tail";
    quest->started = false;
    quest->done = false;
    quest->step_index = 0;
    quest->msg_index = 0;
    quest->messages = messages;
    quest->required = init_required_items();
    quest->rewards = NULL;
    quest->npc_id = 1;
    return quest;
}
