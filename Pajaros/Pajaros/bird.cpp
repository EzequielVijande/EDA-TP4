#include "bird.h"
#include <math.h> /*sqrt()*/
#include <stdlib.h> /*rand()*/

#define MODULO(a) ( a >= 0? a : (a * (-1)) )
#define DIST(p1, p2) (sqrt(pow((p1.getX() - p2.getX()), 2) + pow(p1.getY() - p2.getY(), 2))) 
#define PI	3.14159265359
#define DEG2RAD(ang_deg) ( (((ang_deg) * PI) / 180.0) )

using namespace std;

bird :: bird(unsigned int eyeSight_, unsigned int maxRandomJiggle_, unsigned int speed_, double newDir_, unsigned int xMax_, unsigned int yMax_)
{
	secuenceMax = 16;
	eyeSight = eyeSight_;
	maxRandomJiggle = maxRandomJiggle_;
	speed = speed_;
	newDirection = newDir_;
	xMax = xMax_;
	yMax = yMax_;
	p.setX(rand()%xMax_);
	p.setY(rand()%yMax_);
	currentDirection = rand() % 360;
	secuence = rand()% secuenceMax;
}

void bird :: calculateNewDir(bird * birds, unsigned int birdCount)
{
	int seen_birds = 0;
	double dir_suma = 0.0;
	double dir_prom = 0.0;
	double dir_new = 0.0;
	double direction_aux = 0.0; //le resta una vuelta a las direcciones que se exceden de 360
	
	for (unsigned int j = 0; j < birdCount; j++) //observo los demas pájaros
	{
		if (DIST(birds[j].p, p) <= eyeSight) //observo en el radio eyeSight (también el pajaro se observa asi mismo)
		{
			seen_birds++; //cuento cuantos pajaros estan en el radio (eyeSight)
			direction_aux = (birds[j]).currentDirection;
			if(direction_aux>360)
			{
				direction_aux = (int)direction_aux%360; //acomoda la direccion si esta supera los 360 grados
			}
			dir_suma += direction_aux;
		}
	}
	
	dir_prom = seen_birds != 0 ? (dir_suma / (double)seen_birds) : currentDirection; //solo si hubo pajaros en el radio, se cambia la direccion
	
	dir_new = (dir_prom)+(rand() % maxRandomJiggle);
	if (dir_new > 360)
	{
		dir_new = (int)dir_new % 360; //acomoda la direccion si esta supera los 360 grados
	}
	setDir(dir_new);
}

void bird :: move(void)
{
	currentDirection = newDirection;
	p.setX(p.getX() + cos(DEG2RAD(currentDirection)));
	p.setY(p.getY() - sin(DEG2RAD(currentDirection)));
	if (p.getX() > xMax)
	{
		p.setX((p.getX())- xMax);
	}
	else if ((p.getX()) < 0)     //mundo toroidal
	{
		p.setX(xMax+(p.getX()));
	}
	if (p.getY() > yMax)
	{
		p.setY((p.getY())- yMax);
	}
	else if (p.getY() < 0)
	{
		p.setY(yMax+(p.getY()));
	}

	secuence++;
	if (secuence > secuenceMax)
	{
		secuence = 0;
	}
}

void bird ::incrementEyeSight(void)
{
	eyeSight++;
}
void bird ::decrementEyeSight(void)
{
	eyeSight--;
}
void bird ::incrementSpeed(void)
{
	speed++;
}
void bird ::decrementSpeed(void)
{
	if (speed > 1)
	{
		speed--;
	}
}
void bird :: incrementDir(void)
{
	newDirection++;
	if (newDirection > 360)
	{
		newDirection -= 360;
	}
}
void bird::decrementDir(void)
{
	newDirection--;
	if (newDirection < 0)
	{
		newDirection += 360;
	}
}
possition bird::getPos(void)
{
	return p;
}
double bird :: getDir(void)
{
	return currentDirection;
}
unsigned int bird::getSecuence(void)
{
	return secuence;
}

void bird::setDir(double newDir_)
{
	newDirection = newDir_;
}
unsigned int bird :: getSpeed(void)
{
	return speed;
}
void bird :: setSpeed(unsigned int speed_)
{
	speed = speed_;
}
unsigned int bird ::getEyeSight(void)
{
	return eyeSight;
}
void bird :: setEyeSight(unsigned int eyeSight_)
{
	eyeSight = eyeSight_;
}
unsigned int bird :: getMaxRandomJiggle(void)
{
	return maxRandomJiggle;
}
void bird :: setMaxRandomJiggle(unsigned int maxJiggle_)
{
	maxRandomJiggle = maxJiggle_;
}
void bird :: setXmax(unsigned int x_)
{
	xMax = x_;
}
unsigned int bird :: getXmax(void)
{
	return xMax;
}
void bird::setYmax(unsigned int y_)
{
	yMax = y_;
}
unsigned int bird::getYmax(void)
{
	return yMax;
}


bird::~bird()
{
}
