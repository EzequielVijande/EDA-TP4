#include "simulation.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>

#define BACKGROUND_IMAGE "../Imagenes/sky.png"
#define FONT "../Fonts/sky.ttf"
#define FONT_SIZE 10

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

	//parsecmdline
	//
	simulation sim1(20); //creo simulación con 20 pajaros (enrealidad debo pasarle parametros que ha de procesar el parsecmdline mas arriba...)

	//viewer view(...);
	//controller control(...);
	//while(control.isnotexit())
	//{
	//control.update();
	sim1.update();
	//view.update();
	//al_flip_display();
	//}
	return 0;
}