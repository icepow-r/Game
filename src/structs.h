#ifndef STRUCTS
#define STRUCTS

#include <SDL2/SDL.h>
#include "constants.h"

typedef struct
{
	void (*update)(void);
	void (*draw)(void);
} Delegate;

typedef struct
{
	int x;
	int y;
} Mouse;

typedef struct
{
    float x, y;
    float was_x, was_y;
    float velocity;
    float angle;
	int was_fire;
} Bullet;

typedef struct Widget
{
	char name[MAX_NAME_LENGTH];
	int x;
	int y;
	char label[MAX_NAME_LENGTH];
	struct Widget *prev;
	struct Widget *next;
	void (*action)(void);
} Widget;

typedef struct
{
	Bullet bullet;
	Delegate delegate;
	SDL_Renderer *renderer;
	SDL_Window *window;
	Mouse mouse;
	int keyboard[MAX_KEYBOARD_KEYS];
	Widget *active_widget;
} App;

#endif /* STRUCTS */
