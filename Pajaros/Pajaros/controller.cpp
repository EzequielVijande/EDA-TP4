#include "controller.h"
#define SPEED_INC ALLEGRO_KEY_S
#define SPEED_DEC ALLEGRO_KEY_C
#define EYE_INC ALLEGRO_KEY_E
#define EYE_DEC ALLEGRO_KEY_B
#define JIGGLE_INC ALLEGRO_KEY_J
#define JIGGLE_DEC ALLEGRO_KEY_G

#define FPS (60.0) //velocidad del juego

controller:: controller(ALLEGRO_DISPLAY* display)
{
	exit = false;
	init = true;
	al_install_mouse();
	al_install_keyboard();
	ev_line = al_create_event_queue();
	if (ev_line == NULL)
	{
		init = false;
	}
	if (init)
	{


		timer = al_create_timer(1.0 / FPS);
		if (timer == NULL)
		{
			init = false;
			al_destroy_event_queue(ev_line);
		}
		if (init)
		{

			al_register_event_source(ev_line, al_get_display_event_source(display));
			al_register_event_source(ev_line, al_get_mouse_event_source());
			al_register_event_source(ev_line, al_get_keyboard_event_source());
			al_register_event_source(ev_line, al_get_timer_event_source(timer));
		}

		

		al_start_timer(timer);
	}

}

controller:: ~controller()
{
	if (init)
	{
		al_destroy_event_queue(ev_line);
		al_destroy_timer(timer);


	}
}

void	controller::Update(simulation* sim, viewer* view)
{		
	al_get_next_event(ev_line, &ev);
	possition clicked;
	unsigned int speed = (sim->GetSpeed());
	switch (ev.type)
	{
	case  ALLEGRO_EVENT_KEY_DOWN:

		switch (ev.keyboard.keycode)
		{
			case SPEED_INC:
				sim->incrementSpeed(true);
					break;

			case SPEED_DEC:
				sim->decrementSpeed(true);
					break;

			case EYE_INC:
				sim->incrementEyeSight(true);
					break;

			case EYE_DEC:
				sim->decrementEyeSight(true);
				break;

			case JIGGLE_INC:
				sim->incrementJiggle(true);
				break;

			case JIGGLE_DEC:
				sim->decrementJiggle(true);
				break;

			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				break;
		}
		break;
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		exit = true;
		break;
	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
		clicked.setX(ev.mouse.x);
		clicked.setY(ev.mouse.y);
		sim->changeDir(clicked);
		break;
	case ALLEGRO_EVENT_TIMER:
		//if (!(ev.timer.count % ((int)FPS))) // Determina la velocidad del juego
		//view->UpdateDisplay(sim->GetBirdHeap(), sim->getBirdCount());
		if (!(ev.timer.count % ((int)FPS/9)))
		{
			sim->update();
			view->UpdateDisplay(sim->GetBirdHeap(), sim->getBirdCount());
			al_flip_display();
		}
		break;
	

	}

}

bool controller::IsNotExit(void)
{
	return (!exit);
}

bool controller::IsInitOK(void)
{
	return init;
}
	


