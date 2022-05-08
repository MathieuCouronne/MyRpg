/*
** EPITECH PROJECT, 2021
** quests.h
** File description:
** Initialize quests
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "menu.h"
#include "my_rpg.h"
#include "character.h"
#include "macros.h"
#include "structs.h"

static sfText *init_message(sfFont *font)
{
    sfText *text = sfText_create();

    if (!text)
        return NULL;
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    return text;
}

static game_asset_t *init_quest_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(QUEST_BG_PATH, NULL);
    if (!background->sprite || !background->texture)
        return NULL;
    sfSprite_setTexture(background->sprite, background->texture, false);
    return background;
}

quests_t *init_quests(void)
{
    quests_t *quests = malloc(sizeof(quests_t));
    sfFont *font = sfFont_createFromFile(ARIAL_FONT_PATH);

    if (!quests || !font)
        return NULL;
    quests->current = 0;
    quests->speaking = false;
    quests->quests = malloc(sizeof(quest_t *) * (QUEST_AMOUNT + 1));
    quests->asset = init_quest_background();
    quests->text = init_message(font);
    if (!quests->asset || !quests->text || !quests->quests)
        return NULL;
    quests->quests[0] = create_first_quest();
    quests->quests[1] = create_second_quest();
    quests->quests[2] = create_third_quest();
    quests->quests[3] = NULL;
    if (!quests->text)
        return NULL;
    return quests;
}
