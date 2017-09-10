#include "possition.h"

using namespace std;

possition::possition(double x_, double y_)
{
	x = x_;
	y = y_;
}

double possition :: getX(void)
{
	return x;
}
void possition::setX(double x_)
{
	x = x_;
}
double possition::getY(void)
{
	return y;
}
void possition::setY(double y_)
{
	y = y_;
}


possition::~possition()
{
}
