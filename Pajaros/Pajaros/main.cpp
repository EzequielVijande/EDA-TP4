#include "simulation.h"
#include "output.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
#include <stdlib.h>

#define BACKGROUND_IMAGE "../Imagenes/sky.png"
#define FONT "../Fonts/Font.ttf"


#define HEIGHT 70
#define WIDTH 100

//Seagull Images
#define S0 "../Imagenes/S0.PNG"
#define S1 "../Imagenes/S1.PNG"
#define S2 "../Imagenes/S2.PNG"
#define S3 "../Imagenes/S3.PNG"
#define S4 "../Imagenes/S4.PNG"
#define S5 "../Imagenes/S5.PNG"
#define S6 "../Imagenes/S6.PNG"
#define S7 "../Imagenes/S7.PNG"
#define S8 "../Imagenes/S8.PNG"
#define S9 "../Imagenes/S9.PNG"
#define S10 "../Imagenes/S10.PNG"
#define S11 "../Imagenes/S11.PNG"
#define S12 "../Imagenes/S12.PNG"
#define S13 "../Imagenes/S13.PNG"
#define S14 "../Imagenes/S14.PNG"
#define S15 "../Imagenes/S15.PNG"

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
	char* seagulls[FRAMES] = {S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15};
	//Inicializo arreglo con paths de gaviotas

	srand(time(NULL));
	//parsecmdline
	//
	simulation sim1(20); //creo simulación con 20 pajaros (enrealidad debo pasarle parametros que ha de procesar el parsecmdline mas arriba...)

	viewer view(HEIGHT, WIDTH, BACKGROUND_IMAGE, FONT, seagulls, FRAMES);
	if (!(view.IsInitOK()))
	{
		cout << "Failed to initialize viewer." << endl;
		return -1;
	}
	//controller control(...);
	//while(control.isnotexit())
	//{
	//control.update();
	for (unsigned int i = 0; i < 500; i++)
	{
		sim1.update();
		view.UpdateDisplay(sim1.GetBirdHeap(), sim1.getBirdCount());
		al_rest(0.05);
		al_flip_display();
	}
	//}
	return 0;
}