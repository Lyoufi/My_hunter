/*
** EPITECH PROJECT, 2017
** lol
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "include/hunter.h"

sfRenderWindow *cr_window(unsigned int width, unsigned int height)
{
	sfRenderWindow	*window;
	sfVideoMode	mode;

	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "MY_HUNTER", sfDefaultStyle, NULL);
	return (window);
}

sfVector2f *shoot_the_duck(sfEvent *shoot, sfVector2f *vec,
			   int *add_speed, sfRenderWindow *window)
{
	static int	count = 0;
	
	if (shoot->type == sfEvtMouseButtonPressed) {
		if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
			if (shoot->mouseButton.x >= vec->x && shoot->mouseButton.x - 110 <= vec->x
			    && shoot->mouseButton.y && shoot->mouseButton.y - 110 <= vec->y ) {
				vec->x = -100;
				vec->y = rand() % 600;
				count = count + 1;
				write(1, "T'as touché le coin coin: ", 27);
				my_put_nbr(count);
				write (1, " fois\n", 6);
				*add_speed = true;
			}	 else
				*add_speed = false;
		} else if (shoot->type == sfEvtKeyPressed) {
			if (shoot->key.code == sfKeyEscape)
				sfRenderWindow_close(window);
		}
	}
	return (vec);
}

sfIntRect *get_rect(void)
{
	sfIntRect *rect = malloc(sizeof(*rect));

	rect->left = 0;
	rect->top = 0;
	rect->width = 110;
	rect->height = 110;
	return (rect);
}

int is_lost(sfVector2f *vec, float vplus)
{
	if (vec->x < 1281) {
		vec->x = vec->x + vplus;
		return (false);
	}
	return (true);
}

int get_event(sfRenderWindow *window, sfVector2f *vec, float *vplus)
{
	int add_speed = false;
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		shoot_the_duck(&event, &*vec, &add_speed, window);
		if (add_speed == true)
			*vplus = *vplus + 0.03;
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
	if (is_lost(&*vec, *vplus) == true)
		return (true);
	return (false);
}

int move_duck(sfClock *clk, sfIntRect *rect)
{
	sfTime time = sfClock_getElapsedTime(clk);
	float sec = time.microseconds / 400000.0;

	if (sec > 1) {
		sfClock_restart(clk);
		rect->left += 110;
		if (rect->left == 330)
			rect->left = 0;
		return (true);
	}
	return (false);
}

int main(void)
{
	sfRenderWindow	*window = cr_window(1280, 720);
	sfIntRect	*rect = get_rect();
	sfTexture	*tt = sfTexture_createFromFile("spritesheet.png", rect);
	sfTexture	*texture = sfTexture_createFromFile("back.png", NULL);
	sfSprite	*duck = sfSprite_create();
	sfSprite	*back = sfSprite_create();
	sfVector2f	vec = {-110, 0};
	sfClock		*clk = sfClock_create();
	sfMusic		*music = sfMusic_createFromFile("scatman.ogg");
	float		vplus = 0.5;

	sfMusic_play(music);
	while (sfRenderWindow_isOpen(window)) {
		if (move_duck(clk, rect) == true)
			tt = sfTexture_createFromFile("spritesheet.png", rect);
		sfSprite_setPosition(duck, vec);
		if (get_event(window, &vec, &vplus) == true)
			break;
		set_texture(texture, back, tt, duck);
		display_window(window, back, duck);
	}
	destroy_ressources(music, texture, duck, back);
	sfRenderWindow_destroy(window);
	return (0);
}
