#include "simulation.h"

using namespace std;

int main(void)
{
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
	//}
}