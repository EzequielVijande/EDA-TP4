#include "simulation.h"
#include "output.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
#include <stdlib.h>

#define BACKGROUND_IMAGE "../Imagenes/sky.png"
#define FONT "../Fonts/Starjedi.ttf"
#define FONT_SIZE 10
#define HEIGHT 70
#define WIDTH 100

using namespace std;


int main(void)
{
	if (!al_init())
	{
		cout << "Failed to initialize Allegro" << endl;
		return -1;
	}
	if (!al_init_primitives_addon())
	{
		cout << "Failed to initialize primitives addon" << endl;
		return -1;
	}

	srand(time(NULL));
	//parsecmdline
	//
	simulation sim1(20); //creo simulación con 20 pajaros (enrealidad debo pasarle parametros que ha de procesar el parsecmdline mas arriba...)

	viewer view(HEIGHT, WIDTH, FONT_SIZE, BACKGROUND_IMAGE, FONT);
	if (!(view.IsInitOK()))
	{
		cout << "Failed to initialize viewer." << endl;
		return -1;
	}
	//controller control(...);
	//while(control.isnotexit())
	//{
	//control.update();
	for (unsigned int i = 0; i < 800; i++)
	{
		sim1.update();
		view.UpdateDisplay(sim1.GetBirdHeap(), sim1.getBirdCount());
		al_rest(0.02);
		al_flip_display();
	}
	//}
	return 0;
}