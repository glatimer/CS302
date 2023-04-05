#include "event.h"
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
    event.h will contain the definitions and members of the event
 	 class that will be used to simulate a race course.
    I will attempt to make the vehicles interact with the racing
    by traversing my DLL roster of contestants and each node will 
    loop through an array of events and then calculate a score.
----------------------------------------------------------------------- */
using namespace std;
using std::string;

// ---------------- race course event ----------------
// default constructor
event::event(void): title(nullptr), event_name(nullptr), intensity(0), duration(0) {}

// param constructor
event::event(string &TITLE, event_type &type)
{
    title = TITLE;
    event_name = ' ';
    intensity = 0; 
    duration = 0;
    interaction = type;
}

// destructor
event::~event(void)
{
    title = ' ';
    event_name = ' ';
    intensity = 0;
    duration = 0;
}

// getter
int event::get_intensity(void) const 
{
    return intensity;
}

// getter
string& event::get_interaction()
{
   switch (interaction)
   {
       case 0:
       {
           event_name = "Collision";
           break;
       }
       case 1:
       {
           event_name = "Rocks Falling";
           break;
       }
       case 2:
       {
           event_name = "Tree Down";
           break;
       }
       case 3:
       {
           event_name = "Power Strip";
           break;
       }
       case 4:
       {
           event_name = "Start";
           break;
       }
       case 5:
       {
           event_name = "Finish";
           break;
       }
       default:
       {
           cerr << "Interaction not found." << endl;
           break;
       }
   }
   return event_name;
}

// display the event info
int event::display(void) 
{
   string display = get_interaction();
   cout << "Title: " << title << endl;
   cout << "Event Type: " << display << endl;
   cout << "Intensity: " << intensity << endl;
   cout << "Duration: " << duration << endl;
   return 0;
}

// set random values to interact with the vehicle 
int event::obstacle(void)
{
    switch (interaction)
    {
        case COLLISION:
	{ 
	    // event log
	    cout << "There was a collision!" << endl;

	    // level 1-10
	    intensity = (1 + (rand() %10));

	    // length 30 - 90 seconds
	    duration =  30 + (rand() %90);
	    
	    break;
	}
        case ROCKS_FALLING:
	{
	    // event log
	    cout << "Rocks are falling! Don't get hit." << endl;
	    // level 1-10
	    intensity =  1 + (rand() %10);

	    // length 30 - 90 seconds
	    duration =  30 + (rand() %90);
	    break;
	}
        case TREE_DOWN:
	{
	    // event log
	    cout << "There is a tree down on the path." << endl;
	    // level 1-10
	    intensity =  1 + (rand() %10);

	    // length 30 - 90 seconds
	    duration =  30 + (rand() %90);
	    break;
	}
        case POWER_STRIP:
	{
	    // event log
	    cout << "You've passed the power strip. EnErGy BoOoOsT!" << endl;
	    // level 1-10
	    intensity =  1 + (rand() %10);

	    // length 30 - 90 seconds
	    duration =  30 + (rand() %90);
	    break;
	}
	case START:
	{
	    cout << "The race has begun and our contestants are"
	         << "\npulling away from the starting line!"
		 << "\nThis is going to be a great race!" << endl;
	    break;
	}
	case FINISH:
	{
	    cout << "The race is over!  Let's check the results." << endl;
	    break;
	}
	default:
	{
	    cerr << "Not an event type." << endl;
	    break;
	}
    }
    return duration;
}

