#include "SDL.h"
#include "SDL_gpu.h"
#include <math.h>
#include "compat.h"
#include "common.h"

void draw_stuff(GPU_Image* bg_base, GPU_Target* bg_target, GPU_Image* image, float x, float y, int state)
{
	if(state == 0)
	{
		GPU_BlitScale(bg_base, NULL, bg_target, bg_target->w/2, bg_target->h/2, bg_target->w/(float)bg_base->w, bg_target->h/(float)bg_base->h);
		
		// First row
		{
			float xx = x + 50;
			float yy = y + 50;
			
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_MULTIPLY);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_DIFFERENCE);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
		}
		
		// Second row
		{
			float xx = x + 50;
			float yy = y + 250;
			
			GPU_SetBlendMode(image, GPU_BLEND_ADD);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_SUBTRACT);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_ADD_COLOR);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_SUBTRACT_COLOR);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
		}
		
		// Third row
		{
			float xx = x + 50;
			float yy = y + 450;
			
			GPU_SetBlendMode(image, GPU_BLEND_DARKEN);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_LIGHTEN);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_PUNCHOUT);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_CUTOUT);
			GPU_BlitScale(image, NULL, bg_target, xx, yy, 0.5f, 0.5f);
		}
		
		GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
	}
	else
	{
		SDL_Color white = {255, 255, 255, 255};
		SDL_Color black = {0, 0, 0, 255};
		
		SDL_Color color1, color2;
		if(state == 1)
		{
			color1 = black;
			color2 = white;
		}
		else
		{
			color1 = white;
			color2 = black;
		}
		
		
		// First row
		{
			float xx = x + 50;
			float yy = y + 50;
			
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_MULTIPLY);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_DIFFERENCE);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
		}
		
		// Second row
		{
			float xx = x + 50;
			float yy = y + 250;
			
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_ADD);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_SUBTRACT);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_ADD_COLOR);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_SUBTRACT_COLOR);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
		}
		
		// Third row
		{
			float xx = x + 50;
			float yy = y + 450;
			
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_DARKEN);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_LIGHTEN);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_PUNCHOUT);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
			
			xx += 200;
			GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
			GPU_CircleFilled(bg_target, xx+30, yy+30, 30, color1);
			GPU_SetBlendMode(image, GPU_BLEND_CUTOUT);
			GPU_CircleFilled(bg_target, xx, yy, 30, color2);
		}
		
		GPU_SetBlendMode(image, GPU_BLEND_NORMAL);
	}
}

int main(int argc, char* argv[])
{
	printRenderers();
	
	GPU_Target* screen = GPU_Init(800, 600, GPU_DEFAULT_INIT_FLAGS);
	if(screen == NULL)
		return -1;
	
	printCurrentRenderer();
	
	GPU_Image* image = GPU_LoadImage("data/test3.png");
	if(image == NULL)
		return -1;
	
	GPU_Image* bg_base = GPU_LoadImage("data/test4.bmp");
	if(bg_base == NULL)
		return -1;
	
	GPU_Image* bg = GPU_CreateImage(screen->w, screen->h, GPU_FORMAT_RGBA);
	GPU_Target* bg_target = GPU_LoadTarget(bg);
	if(bg == NULL || bg_target == NULL)
		return -1;
	
	Uint8* keystates = SDL_GetKeyState(NULL);
	float x = 0, y = 0;
	Uint8 draw_face = 1;
	int state = 0;
	
	
	Uint32 startTime = SDL_GetTicks();
	long frameCount = 0;
	
	Uint8 done = 0;
	SDL_Event event;
	while(!done)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				done = 1;
			else if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_ESCAPE)
					done = 1;
				else if(event.key.keysym.sym == SDLK_f)
					draw_face = !draw_face;
				else if(event.key.keysym.sym == SDLK_SPACE)
				{
					state++;
					if(state > 2)
						state = 0;
				}
			}
		}
		
		if(keystates[KEY_UP])
			y -= 1;
		else if(keystates[KEY_DOWN])
			y += 1;
		if(keystates[KEY_LEFT])
			x -= 1;
		else if(keystates[KEY_RIGHT])
			x += 1;
		
		GPU_ClearRGBA(screen, 150, 150, 150, 255);
		
		// Draw a face under everything
		if(draw_face)
			GPU_BlitScale(image, NULL, screen, screen->w/2, screen->h/2, screen->w/(float)image->w, screen->h/(float)image->h);
		
		GPU_Clear(bg_target);
		
		draw_stuff(bg_base, bg_target, image, x, y, state);
		
		// Put our result on the screen target
		GPU_BlitScale(bg, NULL, screen, screen->w/2, screen->h/2, screen->w/(float)bg->w, screen->h/(float)bg->h);
		
		GPU_Flip(screen);
		
		frameCount++;
		if(frameCount%500 == 0)
			printf("Average FPS: %.2f\n", 1000.0f*frameCount/(SDL_GetTicks() - startTime));
	}
	
	printf("Average FPS: %.2f\n", 1000.0f*frameCount/(SDL_GetTicks() - startTime));
	
	GPU_FreeImage(image);
	GPU_Quit();
	
	return 0;
}


