#ifndef OUTPUT_H
#define OUTPUT_H
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>
#include "bird.h"


#define BIRD_SIZE 4
#define BIRD_COLOR "black"
#define UNIT 12
class viewer //Se ocupa de todo lo relacionado con el output de la simulacion
{
public:
	viewer(unsigned int height_, unsigned int width_, unsigned int font_size, char* img_path, char* font_path);
	~viewer();
	void UpdateDisplay(bird* birds, unsigned int bird_count);
	bool IsInitOK(void);


private:
	
	unsigned int height;
	unsigned int width;
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP* background;
	ALLEGRO_FONT* font;
	bool init;
	bool InitializeResources(char* image, char* font_path, unsigned int font_size);

};

#endif //OUTPUT_H