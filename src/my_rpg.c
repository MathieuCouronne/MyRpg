/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg main file
*/

#include "my_rpg.h"
#include "menu.h"

int main(void)
{
    game_t *game = init_game();
    sfEvent event = {};
    sfTexture *texture = sfTexture_createFromFile("assets/images/map.png", NULL);
    sfSprite *sprite = sfSprite_create();
    game_asset_t *menu = init_menu_background();
    menu_buttons_t *button = init_buttons();

    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 1288, 968});
    sfSprite_setTexture(sprite, texture, sfTrue);

    if (!game)
        return 84;
    game->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    //sfView_setCenter(game->view, (sfVector2f) {500, 500});
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        while (sfRenderWindow_pollEvent(game->window, &event))
            handle_events(game, &event);
        sfRenderWindow_setView(game->window, game->view);
        sfRenderWindow_drawSprite(game->window, menu->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, button->play->asset->sprite, NULL);
        sfRenderWindow_drawText(game->window, button->play->text, NULL);
        sfRenderWindow_drawSprite(game->window, button->settings->asset->sprite, NULL);
        sfRenderWindow_drawText(game->window, button->settings->text, NULL);
        //sfRenderWindow_drawSprite(game->window, sprite, NULL);
        sfRenderWindow_display(game->window);
    }
    menu_destroy_buttons(button);
    destroy_menu(menu);
    destroy_game(game);
}
