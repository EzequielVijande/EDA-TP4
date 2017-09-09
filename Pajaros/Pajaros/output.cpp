#include "output.h"

bool InitializeAllegroOutput(void);
//Inicializa los  addons necesarios de allegro para
//utilizar el modulo de output.


ALLEGRO_BITMAP * load_image_at_size(char* image_name, int size_x, int size_y);
//Devuelve el bitmap de la imagen cargada en el tamano deseado.
//En caso de error devuelve NULL.

void destroy_images(ALLEGRO_BITMAP  **imagen, unsigned int num_imagenes);
//Libera toda la memoria utilizada por las imagenes creadas.


viewer::viewer(unsigned int height_, unsigned int width_,unsigned int font_size, char* img_path, char* font_path)
{
	height = height_;
	width = width_;

	
	init = InitializeAllegroOutput();
	if (init)
	{
		init = InitializeResources(img_path, font_path, font_size);
	}
	
}

viewer:: ~viewer()
{
	if (init)
	{
		al_destroy_bitmap(background);
		al_destroy_font(font);
		al_destroy_display(display);
	}
}

bool viewer::IsInitOK(void)
{
	return init;
}

bool InitializeAllegroOutput(void)
{
	if (!al_init_image_addon())
	{
		return false;
	}
	if (!al_init_font_addon())
	{
		return false;
	}
	if (!al_init_ttf_addon())
	{
		return false;
	}
	
	return true;
}

bool viewer:: InitializeResources(char* path, char* font_path, unsigned int font_size)
{
	display = al_create_display(width, height);
	if (display == NULL)
	{
		return false;
	}
	
	background= load_image_at_size(path, width, height);
	if (background == nullptr)
	{
		al_destroy_display(display);
		return false;
	}

	font = al_load_ttf_font(font_path, font_size, 0);
	if (font == NULL)
	{
		al_destroy_display(display);
		al_destroy_bitmap(background);
		return false;
	}

	return true;
	
}

void destroy_images(ALLEGRO_BITMAP  **imagen, unsigned int num_imagenes)
{
	int i;
	for (i = 0; i<num_imagenes; i++)
	{
		al_destroy_bitmap(imagen[i]);
	}
}

ALLEGRO_BITMAP * load_image_at_size(char* image_name, int size_x, int size_y)
{
	ALLEGRO_BITMAP * image = nullptr;
	ALLEGRO_BITMAP * current_target = nullptr;
	ALLEGRO_BITMAP * resized_image = nullptr;

	current_target = al_get_target_bitmap(); //salva el target original para no perderlo

	image = al_load_bitmap(image_name);
	if (image == nullptr)
	{
		return nullptr;
	}

	resized_image = al_create_bitmap(size_x, size_y);
	if (resized_image == nullptr)
	{
		al_destroy_bitmap(image);
		return nullptr;


	}

	al_set_target_bitmap(resized_image);
	al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image),
		0, 0, size_x, size_y, 0);

	al_set_target_bitmap(current_target); //vuelve al target original
	al_destroy_bitmap(image);
	return resized_image;
}
