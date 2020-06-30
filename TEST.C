#include <stdio.h>
#include <conio.h>
#include "keyboard.h"

int main()
{
	install_key_handler();

	clrscr();
	while (!is_key_pressed(ESC))
	{
		gotoxy(1, 1);
		printf("left   = %d\n", is_key_pressed(LEFT));
		printf("right  = %d\n", is_key_pressed(RIGHT));
		printf("up     = %d\n", is_key_pressed(UP));
		printf("down   = %d\n", is_key_pressed(DOWN));
		printf("butt Z = %d\n", is_key_pressed(Z));
		printf("butt X = %d\n", is_key_pressed(X));
	}

	uninstall_key_handler();
}
