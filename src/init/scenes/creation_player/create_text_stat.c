/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

sfText ***create_stat_text(sfFont *font)
{
    sfText ***text = malloc(sizeof(sfText **) * 4);
    float shifts[5] = {515, 585, 655, 730, 800};
    int class_stats[3][5] = {
        {BASE_WAR_STR, BASE_WAR_DEF, BASE_WAR_VIT, BASE_WAR_SPD, BASE_WAR_DEX},
        {BASE_MAGE_STR, BASE_MAGE_DEF, BASE_MAGE_VIT, BASE_MAGE_SPD, BASE_MAGE_DEX},
        {BASE_DOG_STR, BASE_DOG_DEF, BASE_DOG_VIT, BASE_DOG_SPD, BASE_DOG_DEX}
    };

    for (size_t i = 0; i < 3; i++) {
        text[i] = malloc(sizeof(sfText *) * 6);
        for (size_t y = 0; y < 5; y++) {
            text[i][y] = sfText_create();
            sfText_setFont(text[i][y], font);
            sfText_setString(text[i][y], itoa(class_stats[i][y]));
            sfText_setCharacterSize(text[i][y], 20);
            sfText_setColor(text[i][y], sfWhite);
            sfText_setPosition(text[i][y], (sfVector2f) {650, shifts[y]});
        }
        text[i][5] = NULL;
    }
    text[3] = NULL;
    return text;
}
