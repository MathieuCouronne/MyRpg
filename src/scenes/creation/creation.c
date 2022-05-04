/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** create creation player scene
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

static void event_handling(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        default_event_handling(game, game->scenes->creation_menu->buttons);
    }
}

void display_buttons_creation(sfRenderWindow *w,
main_creation_scenes_t *creation)
{
    sfRenderWindow_drawSprite(w, creation->buttons[0]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[1]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[2]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[3]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[4]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[5]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[6]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[7]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[8]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[9]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[10]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[11]->asset->sprite, NULL);
    sfRenderWindow_drawSprite(w, creation->buttons[12]->asset->sprite, NULL);
    sfRenderWindow_drawText(w, creation->buttons[12]->text, NULL);
}

void display_stat(main_creation_scenes_t *creation,
sfRenderWindow *window)
{
    for (size_t i = 0; i < 5; i++) {
        sfRenderWindow_drawText(window,
    creation->stat[creation->class][0], NULL);
        sfRenderWindow_drawText(window,
    creation->stat[creation->class][1], NULL);
        sfRenderWindow_drawText(window,
    creation->stat[creation->class][2], NULL);
        sfRenderWindow_drawText(window,
    creation->stat[creation->class][3], NULL);
        sfRenderWindow_drawText(window,
    creation->stat[creation->class][4], NULL);
    }
}

void set_parameters(game_t *game, main_creation_scenes_t *creation)
{
    sfSprite_setPosition(game->characters
    [creation->class]->sprite, (sfVector2f) {940, 270});
    sfSprite_setScale(game->characters
    [creation->class]->sprite, (sfVector2f) {8.f, 8.f});
}

bool display_creation(game_t *game)
{
    sfRenderWindow *window = NULL;
    main_creation_scenes_t *creation = NULL;

    if (!game || !game->window || !game->scenes ||
    !game->scenes->creation_menu)
        return false;
    window = game->window;
    creation = game->scenes->creation_menu ;
    event_handling(game);
    sfRenderWindow_drawSprite(window, creation->background->sprite, NULL);
    display_buttons_creation(window, creation);
    set_parameters(game, creation);
    sfRenderWindow_drawSprite(window,
    game->characters[creation->class]->sprite, NULL);
    sfText_setPosition(creation->text[creation->class],
    (sfVector2f) {540, 360});
    sfRenderWindow_drawText(window, creation->text[creation->class], NULL);
    display_stat(creation, window);
    return true;
}
