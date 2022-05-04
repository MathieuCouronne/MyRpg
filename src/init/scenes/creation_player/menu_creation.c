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
    scene->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    scene->background = init_creation_background();
    scene->buttons = init_buttons_creation();
    scene->class = 1;
    scene->text = init_text_creation(scene->font);
    return scene;
}
