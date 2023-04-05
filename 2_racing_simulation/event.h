#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
    event.h will contain the definitions and members of the event
 	 class that will be used to simulate a race course.
    I will attempt to make the vehicles interact with the racing
	 events by inputting a vehicle object as an argument.
----------------------------------------------------------------------- */

using std::string;

// different types of obstacle possibilities for building 
// unique and different obstacle courses
enum event_type 
{
    COLLISION,     // 0
    ROCKS_FALLING, // 1
    TREE_DOWN, 	   // 2
    POWER_STRIP,   // 3
    START,	   // 4
    FINISH	   // 5
};

// events that happen to the contestants
class event
{
    public:
    event(void);
    event(string &TITLE, event_type &type);
    ~event(void);
    int obstacle(void);
    int display(void);
    int get_intensity(void) const;
    string& get_interaction();
    
    private:
    string title;
    string event_name;
    int intensity;
    int duration;  // seconds
    event_type interaction;
};

