/*
	video.h
*/

#include <stdlib.h>
#include <stdio.h>

int add(int a, int b);
void change_video_mode(unsigned char mode);

unsigned char far *VGA = (unsigned char far *) 0xa0000000;

unsigned char far *OFFSCREEN;

void create_offscreen()
{
	OFFSCREEN = malloc(320 * 200);
	if (OFFSCREEN == NULL)
	{
		printf("could not allocate memory for offscreen image !");
		exit(-1);
	}
}

void destroy_offscreen()
{
	free(OFFSCREEN);
}

void set_pixel(int x, int y, unsigned char color)
{
	OFFSCREEN[y * 320 + x] = color;
}

void clear_offscreen()
{
	memset(OFFSCREEN, 0, 64000);
}

void show_offscreen()
{
	memcpy(VGA, OFFSCREEN, 64000);
}