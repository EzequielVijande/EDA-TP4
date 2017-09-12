#pragma once

#ifndef BIRD_H_
#define BIRD_H_
#define FRAMES 16

#include "possition.h"
class bird
{
public:
	bird(unsigned int eyeSight_ = 0, unsigned int maxRandomJiggle_ = 0, unsigned int speed_ = 5, double newDir_ = 60, unsigned int xMax_ = 100, unsigned int yMax_ = 70);
	void calculateNewDir(bird * birds, unsigned int birdCount);
	void move(void);

	void incrementEyeSight(void);
	void decrementEyeSight(void);
	void incrementSpeed(void);
	void decrementSpeed(void);
	void incrementDir(void);
	void decrementDir(void);
	possition getPos(void);
	double getDir(void);
	unsigned int getSecuence(void);
	void setDir(double);
	unsigned int getSpeed(void);
	void setSpeed(unsigned int);
	unsigned int getEyeSight(void);
	void setEyeSight(unsigned int);
	unsigned int getMaxRandomJiggle(void);
	void setMaxRandomJiggle(unsigned int);
	void setXmax(unsigned int);
	unsigned int getXmax(void);
	void setYmax(unsigned int);
	unsigned int getYmax(void);
	~bird();
private:
	
	possition p;
	double currentDirection;
	double newDirection;
	unsigned int eyeSight;
	unsigned int maxRandomJiggle;
	unsigned int speed;
	unsigned int xMax;
	unsigned int yMax;
	unsigned int secuence;     //instancia de vuelo o de aleteo
	unsigned int secuenceMax;  //aleteo máximo
};

#endif // !BIRD_H_