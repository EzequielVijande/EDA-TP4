#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <allegro5\allegro.h>
#include "simulation.h"
#include "output.h"

class controller //clase que se ocupa de administrar los recursos
{
public:
	controller(ALLEGRO_DISPLAY* display);
	bool IsNotExit(void);
	bool IsInitOK(void);
	~controller();
	void Update(simulation* sim, viewer* view);

private:
	bool exit;
	bool init;
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE* ev_line;
	ALLEGRO_TIMER* timer;
};


#endif //CONTROLLER_H

