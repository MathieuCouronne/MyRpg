/*
** EPITECH PROJECT, 2021
** close.c
** File description:
** Close window
*/

#include <SFML/Graphics.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"
#include "my.h"

static const char KEYS[27][2] = {
    {'a', sfKeyA},
    {'b', sfKeyB},
    {'c', sfKeyC},
    {'d', sfKeyD},
    {'e', sfKeyE},
    {'f', sfKeyF},
    {'g', sfKeyG},
    {'h', sfKeyH},
    {'i', sfKeyI},
    {'j', sfKeyJ},
    {'k', sfKeyK},
    {'l', sfKeyL},
    {'m', sfKeyM},
    {'n', sfKeyN},
    {'o', sfKeyO},
    {'p', sfKeyP},
    {'q', sfKeyQ},
    {'r', sfKeyR},
    {'s', sfKeyS},
    {'t', sfKeyT},
    {'u', sfKeyU},
    {'v', sfKeyV},
    {'w', sfKeyW},
    {'x', sfKeyX},
    {'y', sfKeyY},
    {'z', sfKeyZ},
    {'_', sfKeySpace}
};

static char get_key(sfKeyCode code)
{
    for (unsigned int i = 0; i < 27; i++) {
        if (KEYS[i][1] == code)
            return KEYS[i][0];
    }
    return -1;
}

static sfRenderWindow *init_input_window(void)
{
    char *title = "Choose your name";
    sfVideoMode mode = {500, 40, 32};
    sfUint32 style = sfClose;
    sfRenderWindow *help = sfRenderWindow_create(mode, title, style, NULL);

    sfRenderWindow_setFramerateLimit(help, 64);
    return help;
}

static sfText *init_input_text(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(ARIAL_FONT_PATH);

    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f) {0, 0});
    sfText_setColor(text, sfBlack);
    sfText_setString(text, "");
    return text;
}

static void handle_input_events(input_t *input)
{
    char key = -1;
    sfEvent *event = input->event;

    if (event->type == sfEvtClosed ||
    (event->type == sfEvtKeyPressed && event->key.code == sfKeyEnter))
        sfRenderWindow_close(input->window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyBack && input->pos != 0) {
            input->string[--input->pos] = '\0';
        } else if (input->pos != 1024 - 3 &&
        (key = get_key(event->key.code)) != -1) {
            input->string[input->pos++] = key;
        }
        sfText_setString(input->text, input->string);
    }
}

char *get_text_input(game_t *game)
{
    input_t input = {init_input_window(), malloc(sizeof(sfEvent)),
    init_input_text(), malloc(sizeof(char) * 1024), 0};

    if (!input.window || !input.text || !input.string)
        return "Error";
    memset(input.string, '\0', 1024);
    sfRenderWindow_setVisible(game->window, false);
    while (sfRenderWindow_isOpen(input.window)) {
        sfRenderWindow_clear(input.window, sfWhite);
        sfRenderWindow_drawText(input.window, input.text, NULL);
        while (sfRenderWindow_pollEvent(input.window, input.event))
            handle_input_events(&input);
        sfRenderWindow_display(input.window);
    }
    sfRenderWindow_setVisible(game->window, true);
    sfRenderWindow_destroy(input.window);
    return input.string;
}
