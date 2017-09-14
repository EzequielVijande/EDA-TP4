#ifndef OUTPUT_H
#define OUTPUT_H
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_color.h>
#include "bird.h"


#define BIRD_SIZE 40
#define BIRD_COLOR "black"
#define UNIT 10
#define FRAMES 16
class viewer //Se ocupa de todo lo relacionado con el output de la simulacion
{
public:
	viewer(unsigned int height_, unsigned int width_, char* img_path, char* font_path, char** seagulls, unsigned int n_seagulls);
	~viewer();
	void UpdateDisplay(bird* birds, unsigned int bird_count);
	bool IsInitOK(void);
	ALLEGRO_DISPLAY* GetDisplay(void);

private:
	
	unsigned int height;
	unsigned int width;
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP* background;
	ALLEGRO_BITMAP* seagull[FRAMES];
	ALLEGRO_FONT* font;
	double font_size;
	bool init;
	bool InitializeResources(char* image, char* font_path, unsigned int font_size, char** seagulls, unsigned int n_seagulls);
	void PrintText(bird* birds);

};

#endif //OUTPUT_H