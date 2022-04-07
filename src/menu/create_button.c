/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"

button_t *init_button(char *str, sfVector2f pos, sfVector2f pos_sprite)
{
    button_t *button = malloc(sizeof(button_t));
    button->asset = malloc(sizeof(game_asset_t));

    button->font = sfFont_createFromFile("./font/LifeCraft_Font.ttf");
    button->text = sfText_create();
    button->asset->sprite = sfSprite_create();
    button->asset->texture = sfTexture_createFromFile
        ("./assets/images/button_asset.png", NULL);
    sfSprite_setTexture(button->asset->sprite, button->asset->texture, sfTrue);
    sfSprite_setPosition(button->asset->sprite, pos_sprite);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, str);
    sfText_setCharacterSize(button->text, 60);
    sfText_setColor(button->text, sfBlack);
    sfText_setPosition(button->text, pos);
    return button;
}

menu_buttons_t *init_buttons(void)
{
    menu_buttons_t *button = malloc(sizeof(menu_buttons_t));

    button->play = init_button("Play", (sfVector2f){920,530},
                        (sfVector2f){800,500});
    button->settings = init_button("Settings",(sfVector2f){885,680},
                        (sfVector2f){800,650});
    return button;
}
