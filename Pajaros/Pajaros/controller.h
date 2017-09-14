#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <allegro5\allegro.h>
#include "simulation.h"
#include "output.h"

class controller //clase que se ocupa de administrar los recursos
{
public:
	controller(ALLEGRO_DISPLAY* display, unsigned int speed);
	bool IsNotExit(void);
	bool IsInitOK(void);
	~controller();
	void Update(simulation*);

private:
	bool exit;
	bool init;
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE* ev_line;
	ALLEGRO_TIMER* timer;
};


#endif //CONTROLLER_H

