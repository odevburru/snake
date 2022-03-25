#include <allegro.h>
#include <stdio.h>
#include "obj.h"

void control();

obj snake, food;
int spd; bool d[3];
void dd(int da){for(int i=0; i<=3; i++){d[i]=false;}d[da]=true;}

obj poses_s[256];

int main()
{
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 480, 480, 0, 0);
	install_keyboard();

	BITMAP *buff = create_bitmap(480, 480);
	snake = {90, 90, 120, 120, 0xaaaaaa}; food = {30, 30, 60, 60, 0x888888};
	spd = 30;
	
	while(!key[KEY_ESC])
	{
		control();
		
		rectfill(buff, snake.x, snake.y, snake.w, snake.h, snake.color);
		rectfill(buff, food.x, food.y, food.w, food.h, food.color);
		
		draw_sprite(screen, buff, 0, 0);
		clear_to_color(buff, 0xdddddd);
		rest(70);
	}
}
END_OF_MAIN();

void control()
{
	if(d[0] || key[KEY_W]) {snake.y -= spd; dd(0);}
	if(d[1] || key[KEY_A]) {snake.x -= spd; dd(1);}
	if(d[2] || key[KEY_S]) {snake.y += spd; dd(2);}
	if(d[3] || key[KEY_D]) {snake.x += spd; dd(3);}
	
	snake.w = snake.x + 32;
	snake.h = snake.y + 32;
	
	if(colision(snake, food) == 1)
	{
		food.x = rand() % 16*30 + 1;
		food.y = rand() % 16*30 + 1;
		
		food.w = food.x + 32;
		food.h = food.y + 32;
	}
}
