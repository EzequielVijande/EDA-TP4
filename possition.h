#pragma once
#ifndef POSSITION_H_
#define POSSITION_H_


class possition
{
public:
	possition(double x_ = 0, double y_ = 0);
	double getX(void);
	double getY(void);
	void setX(double x_);
	void setY(double y_);
	~possition();   /////////////
	double x;
	double y;
private:
	
};

#endif //!POSSITION_H_