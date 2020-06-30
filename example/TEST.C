#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "graphic\video.h"
#include "keyboard\keyboard.h"
#include "timer\timer.h"

float px, py, vx, vy;
char running;

unsigned int *clock = (unsigned int *) 0x0000046c;

void free_memory()
{
	change_video_mode(0x03);
	uninstall_key_handler();
	destroy_offscreen();
}

void update()
{
	if (is_key_pressed(LEFT))
	{
		vx = -2;
	}
	else if (is_key_pressed(RIGHT))
	{
		vx = 2;
	}
	else {
		vx = 0;
	}

	if (px < 0)
	{
		vx = 0;
		px = 0;
	}
	if (px > 303)
	{
		px = 303;
		vx = 0;
	}

	/*
	if (is_key_pressed(UP))
	{
		vy -= 4;
	}
	else if (is_key_pressed(DOWN))
	{
		vy += 4;
	}
	else {
		vy = 0;
	}
	*/

	if (py < 180)
	{
		vy += 0.3;
	}
	else
	{
		vy = 0;
		py = 180;
	}

	if (is_key_pressed(Z))
	{
		vy = -3;
	}

	if (is_key_pressed(ESC))
	{
		running = 0;
	}

	px = px + vx;
	py = py + vy;
}

void draw_player()
{
	int x, y;
	x = (int) py * 320 + (int) px;
	for (y = 0; y < 16; y++)
	{
		memset(&OFFSCREEN[x], 15, 16);
		x += 320;
	}
}

void main()
{
	unsigned int time;
	int x, y, tx, ty;

	install_fast_clock();
	install_key_handler();
	change_video_mode(0x13);

	create_offscreen();

	printf("add = %d\n", add(15, 37));

	running = 1;

	while (running)
	{
		time = *clock + 20;

		update();

		clear_offscreen();
		draw_player();
		show_offscreen();

		while (time >= *clock);
	}

	free_memory();
}