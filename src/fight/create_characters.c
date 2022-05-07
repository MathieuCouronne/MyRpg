/*
** EPITECH PROJECT, 2021
** create_characters.c
** File description:
** Creates a characer
*/

#include "structs.h"
#include "my_rpg.h"
#include "inventory.h"
#include "macros.h"

player_t *create_dogwarrior(void)
{
    player_t *dogwarrior = malloc(sizeof(player_t));

    if (!dogwarrior)
        return NULL;
    dogwarrior->sprite = sfSprite_create();
    dogwarrior->position = &((sfVector2f) {260, 270});
    dogwarrior->texture = sfTexture_createFromFile(DOGWARRIOR_PATH, NULL);
    dogwarrior->rect = &((sfIntRect) {398, 168, 45, 60});
    sfSprite_setTexture(dogwarrior->sprite, dogwarrior->texture, sfTrue);
    sfSprite_setScale(dogwarrior->sprite, (sfVector2f) {7, 7});
    sfSprite_setPosition(dogwarrior->sprite, *(dogwarrior->position));
    sfSprite_setTextureRect(dogwarrior->sprite, *(dogwarrior->rect));
    return dogwarrior;
}

player_t *create_mage(void)
{
    player_t *mage = malloc(sizeof(player_t));

    if (!mage)
        return NULL;
    mage->sprite = sfSprite_create();
    mage->position = &((sfVector2f) {300, 290});
    mage->texture = sfTexture_createFromFile(MAGE_PATH, NULL);
    mage->rect = &((sfIntRect) {177, 172, 29, 56});
    sfSprite_setTexture(mage->sprite, mage->texture, sfTrue);
    sfSprite_setScale(mage->sprite, (sfVector2f) {7, 7});
    sfSprite_setPosition(mage->sprite, *(mage->position));
    sfSprite_setTextureRect(mage->sprite, *(mage->rect));
    return mage;
}

player_t *create_warrior(void)
{
    player_t *war = malloc(sizeof(player_t));

    if (!war)
        return NULL;
    war->sprite = sfSprite_create();
    war->position = &((sfVector2f) {250, 290});
    war->texture = sfTexture_createFromFile(WARRIOR_PATH, NULL);
    war->rect = &((sfIntRect) {397, 171, 45, 58});
    sfSprite_setTexture(war->sprite, war->texture, sfTrue);
    sfSprite_setScale(war->sprite, (sfVector2f) {7, 7});
    sfSprite_setTextureRect(war->sprite, *(war->rect));
    sfSprite_setPosition(war->sprite, *(war->position));
    return war;
}

player_t **create_characters(void)
{
    player_t **characters = malloc(sizeof(player_t *) * 4);

    if (!characters)
        return NULL;
    characters[0] = create_warrior();
    characters[1] = create_mage();
    characters[2] = create_dogwarrior();
    characters[3] = NULL;
    for (unsigned int i = 0; i < 3; i++) {
        if (!characters[i])
            return NULL;
    }
    return characters;
}
