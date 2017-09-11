#include "simulation.h"
#include <stdlib.h>  /*rand()*/
#include <math.h> /*atan()*/

#define PI	3.14159265359
#define RAD2DEG(ang_rad) ( (ang_rad * 180)/PI )
#define DIST(p1, p2) (sqrt(pow((p1.getX() - p2.getX()), 2) + pow(p1.getY() - p2.getY(), 2)))

using namespace std;

simulation :: simulation(unsigned int birdCount_)
{
	birdCount = birdCount_;
	if (birdCount > 0)
	{
		speedIncremented = false;  //inicializo datos miembros de la simulación
		speedDecremented = false;
		dirChanged = false;
		pointToAim.setX(0);
		pointToAim.setY(0);
		dirIncremented = false;
		dirDecremented = false;
		eyeChanged = false;
		eyeAux = false;
		eyeIncremented = false;
		eyeDecremented = false;
		birdAdded = false;
		birdDeleted = false;

		birds = new bird[birdCount];  //creo los pájaros

		for (unsigned int i = 0; i < birdCount; i++)
		{
			birds[i].setDir(rand() % 360);  //seteo todos los pajaros con una direccion random entre 0 y 360 (grados)
			birds[i].setMaxRandomJiggle(3); //seteo para todos un meneo maximo de 8 (grados)
			birds[i].setEyeSight(4);  //seteo alcance
			birds[i].setSpeed(20);
			birds[i].setXmax(100);
			birds[i].setYmax(70);
		}
	}
}
void simulation::update(void)
{
	double delta_x = 0;
	double delta_y = 0;
	double ang_rad = 0;

	for (unsigned int i = 0; i < birdCount; i++)
	{
		birds[i].calculateNewDir(birds, birdCount);
	}
	for (unsigned int i = 0; i < birdCount; i++)
	{
		if (speedIncremented)
		{
			birds[i].incrementSpeed();
			speedIncremented = false;
		}
		if (speedDecremented)
		{
			birds[i].decrementSpeed();
			speedDecremented = false;
		}
		if (dirIncremented)
		{
			birds[i].incrementDir();
			dirIncremented = false;
		}
		if (dirDecremented)
		{
			birds[i].decrementDir();
			dirDecremented = false;
		}
		if (eyeIncremented)
		{
			birds[i].incrementEyeSight();
			eyeIncremented = false;
		}
		if (eyeDecremented)
		{
			birds[i].decrementEyeSight();
			eyeDecremented = false;
		}
		if (dirChanged)
		{
			if (DIST(birds[i].getPos(), pointToAim) < birds[i].getEyeSight())
			{
				delta_x = birds[i].getPos().getX() - pointToAim.getX();   //diferencia entre la ubicacion del pajaro y el punto de acumulacion (pointToAim)
				delta_y = birds[i].getPos().getY() - pointToAim.getY();
				if (delta_x == 0)
				{
					if (delta_y > 0)
					{
						birds[i].setDir(90);    //direccion hacia arriba
					}
					else if (delta_y < 0)
					{
						birds[i].setDir(270); //direccion hacia abajo
					}
				}
				else if (delta_y == 0)
				{
					if (delta_x > 0)
					{
						birds[i].setDir(180);    //direccion hacia la izquierda
					}
					else if (delta_x < 0)
					{
						birds[i].setDir(0); //direccion hacia la derecha
					}
				}
				else
				{
					ang_rad = atan(delta_y / delta_x);
					ang_rad = (ang_rad >= 0 ? ang_rad + PI : ((ang_rad * (-1)) + PI));   //direccion hacia el punto de acumulación
					birds[i].setDir(RAD2DEG(ang_rad));
				}
			}
			dirChanged = false;
		}
	}
	for (unsigned int i = 0; i < birdCount; i++)
	{
		birds[i].move();
	}
}
void simulation :: incrementSpeed(bool speedState_)
{
	speedIncremented = speedState_;
}
void simulation :: decrementSpeed(bool speedState_)
{
	speedDecremented = speedState_;
}
void simulation :: changeDir(possition pointToAim_)
{
	dirChanged = true;
	pointToAim = pointToAim_;
}
void simulation :: incrementDir(bool dirState_)
{
	dirIncremented = dirState_;
}
void simulation::decrementDir(bool dirState_)
{
	dirDecremented = dirState_;
}
void simulation :: changeEyeSight(unsigned int eyeAux_)
{
	eyeChanged = true;
	eyeAux = eyeAux_;
}
void simulation::incrementEyeSight(bool eyeState_)
{
	eyeIncremented = eyeState_;
}
void simulation::decrementEyeSight(bool eyeState_)
{
	eyeDecremented = eyeState_;
}
bool simulation :: isSpeedIncremented(void)
{
	return speedIncremented;
}
bool simulation::isSpeedDecremented(void)
{
	return speedDecremented;
}
bool simulation::isDirChanged(void)
{
	return dirChanged;
}
possition simulation::getPointToAim(void)
{
	return pointToAim;

}
bool simulation::isDirIncremented(void)
{
	return dirIncremented;
}
bool simulation::isDirDecremented(void)
{
	return dirDecremented;
}
bool simulation::isEyeChanged(void)
{
	return eyeChanged;
}
double simulation::getEyeAux(void)
{
	return eyeAux;
}
bool simulation::isEyeIncremented(void)
{
	return eyeIncremented;
}
bool simulation::isEyeDecremented(void)
{
	return eyeDecremented;
}
unsigned int simulation::getBirdCount(void)
{
	return birdCount;
}

bird* simulation::GetBirdHeap(void)
{
	return birds;
}

void simulation::addBird(bool)
{
	birdAdded = true;
}
void simulation::deleteBird(bool)
{
	birdDeleted = true;
}


simulation :: ~simulation()
{
	delete[](birds);
}