/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_creation_background()
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(CREATION_BG_PATH, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

main_creation_scenes_t *init_creation(void)
{
    main_creation_scenes_t *scene = malloc(sizeof(main_creation_scenes_t));

    if (!scene)
        return NULL;
    scene->stats = malloc(sizeof(int *) * 4);
    scene->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    scene->background = init_creation_background();
    scene->buttons = init_buttons_creation();
    scene->class = 0;
    scene->text = init_text_creation(scene->font);
    scene->stats[0] = (int [5])
    {BASE_WAR_STR, BASE_WAR_DEF, BASE_WAR_VIT, BASE_WAR_SPD, BASE_WAR_DEX};
    scene->stats[1] = (int [5])
    {BASE_MAGE_STR, BASE_MAGE_DEF, BASE_MAGE_VIT, BASE_MAGE_SPD, BASE_MAGE_DEX};
    scene->stats[2] = (int [5])
    {BASE_DOG_STR, BASE_DOG_DEF, BASE_DOG_VIT, BASE_DOG_SPD, BASE_DOG_DEX};
    scene->stats[3] = NULL;
    scene->stat = create_stat_text(scene->font, scene);
    return scene;
}
