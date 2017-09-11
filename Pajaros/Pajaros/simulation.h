#pragma once
#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "bird.h"

class simulation
{
public:
	simulation(unsigned int birdCount_ = 0);
	void update(void);

	void incrementSpeed(bool);  //setters
	void decrementSpeed(bool);
	void changeDir(possition pointToAim_);
	void incrementDir(bool);
	void decrementDir(bool);
	void changeEyeSight(unsigned int eyeAux_);
	void incrementEyeSight(bool);
	void decrementEyeSight(bool);
	void addBird(bool);
	void deleteBird(bool);
	bool isSpeedIncremented(void);  //getters
	bool isSpeedDecremented(void);
	bool isDirChanged(void);
	possition getPointToAim(void);
	bool isDirIncremented(void);
	bool isDirDecremented(void);
	bool isEyeChanged(void);
	double getEyeAux(void);
	bool isEyeIncremented(void);
	bool isEyeDecremented(void);
	bool isBirdAdded(void);
	bool isBirdDeleted(void);
	unsigned int getBirdCount(void);
	bird* GetBirdHeap(void);
	~simulation();
private:
	
	bird * birds;
	unsigned int birdCount;
	bool speedIncremented;
	bool speedDecremented;
	bool dirChanged;
	possition pointToAim;
	bool dirIncremented;
	bool dirDecremented;
	bool eyeChanged;
	unsigned int eyeAux;
	bool eyeIncremented;
	bool eyeDecremented;
	bool birdAdded;
	bool birdDeleted;
};

#endif // !SIMULATION_H_