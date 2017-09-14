#include <stdlib.h>
#include<iostream>
#include "controller.h"
#include "simulation.h"
#include <allegro5\allegro.h>
#include "ParserFunc.h"
#include "possition.h"

#define BACKGROUND_IMAGE "../Imagenes/sky.png"
#define FONT "../Fonts/Font.ttf"

#define HEIGHT 70
#define WIDTH 100
#define MAX_BIRDS 100
#define ERR -1

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

#define FPS 60 //velocidad del juego

using namespace std;


int
main(int argc, char**argv){
	if (!al_init())
	{
		cout << "Failed to initialize Allegro" << endl;
		return -1;
	}
	/*
	if (!al_init_primitives_addon())
	{
		cout << "Failed to initialize primitives addon" << endl;
		return ERR;
	}
	*/
	char* seagulls[FRAMES] = { S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15 };
	//Inicializo arreglo con paths de gaviotas
	userDataType uData = {0,0};
	srand(time(NULL));
	if (parsecmdline(argc, argv, &Callback, &uData)==-1) {
		cout << "Parsing Error. Recall the program with appropiate argument values." << endl;
		return -1;
	}
	//
	simulation sim1(uData.birdnumber); //creo simulación con cantidad de pajaros definida por usuario.

	viewer view(HEIGHT, WIDTH, BACKGROUND_IMAGE, FONT, seagulls, FRAMES);
	if (!(view.IsInitOK()))
	{
		cout << "Failed to initialize viewer." << endl;
		return -1;
	}
	controller control(view.GetDisplay(),FPS);
	if (!(control.IsInitOK()))
	{
		return -1;
	}

	while(control.IsNotExit)
	{
		control.Update(&sim1);
		sim1.update();
		al_flip_display();
	
	}
	return 0;


}

int
Callback(char *key, char *value, void *userData) {

	int errfl = ON;										//Dado que no se aceptan más de una misma llamada a un parametro, se utiliza un flag 
	userDataType *uData = (userDataType*)userData;		//para verificar que el parametro no fue llamado anteriormente.
														//Se castea el puntero a void por portabilidad del Parser
	if (key == NULL) {
		if (!strcmp(value, "help")) {		//Se agrego un help para el uso del programa.
			help();
			return -1;
		}
		else if (isanumber(value)) {
			if (uData->Flag->birdnumber == OFF) {
				uData->birdnumber = atoi(value);
				if (uData->birdnumber > MAX_BIRDS) {
					errfl = OFF;
				}
				else {
					cout << "Error: Parameter exceeds maximum bird amount. Value given:" << uData->birdnumber << endl;
				}
				uData->Flag->birdnumber = ON;
			}
		}else{
			printf("Error: Program only accepts arguments help or an interger number.\n");
			return ERR;
		}
	}else{
		printf("Error: Program only accepts arguments. No valid -key values exist.");
		return ERR;
	}

	if (errfl == ON) {
		printf("Error: Invalid argument %s! Too many input arguments.\n", value);
		return ERR;
	}
	return OFF;
}

bool isanumber(char* value) {		//No standard function to check if the value string was an interger unless using sscanf. We made our own. 
	for (int i = 0; i<strlen(value); i++) {
		if (isdigit(value[i])); else return false;
	}
	return true;
}

void
help(void) {
	//Created for easy use to new users.
	printf("Welcome to our Bird Simulation!\n");
	printf("This text was written to help new users with the parameters and limitations of the program.\n");
	printf("\n Key Parameters:\n");
	printf("\n This program does not accept key value type parameters, only arguments.\n");
	printf("\nArgument Parameters:\n");
	printf("If the argument is a number, it sets the number of birds for the simulation.\n");
	printf("If the argument is 'help' it calls forth this message.");
	printf("\n");
	printf("\n");
	printf("\n");

}

