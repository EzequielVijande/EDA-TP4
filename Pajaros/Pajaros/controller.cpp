#include "controller.h"
#define SPEED_INC ALLEGRO_KEY_S
#define SPEED_DEC ALLEGRO_KEY_C
#define EYE_INC ALLEGRO_KEY_E
#define EYE_DEC ALLEGRO_KEY_B
#define JIGGLE_INC ALLEGRO_KEY_J
#define JIGGLE_DEC ALLEGRO_KEY_G


controller:: controller(ALLEGRO_DISPLAY* display, unsigned int speed)
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


		timer = al_create_timer(1.0 / (double)speed);
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
		possition clicked(ev.mouse.x, ev.mouse.y);
		sim->changeDir(clicked);
		break;
	case ALLEGRO_EVENT_TIMER:
		view->UpdateDisplay(sim->GetBirdHeap(), sim->getBirdCount());
		break;
	

	}

}
	


