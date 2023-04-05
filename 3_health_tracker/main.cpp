//#include "health_event.h"
#include "app.h"
/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
     main.cpp will manage the client interaction with the Health Tracker
   ........................................................................
   ------------------------------------------------------------------------ */
using namespace std;

int main()
{
    application test;
    int response;
    
    // setup
    test.build_events();
    
    // welcome
    test.greeting(1);

    // Menu Options
    do 
    {
    response = test.greeting(2);

    // User Interface

        switch (response)
        {
            case 1:
	        // add event
		test.add_event();
	        break;
            case 2:
	        // display list
    		test.display_events();
	        break;
            case 3:
	        // edit event
    		test.edit_event();
	        break;
            case 4:
	        // complete task
    		test.complete_task();
	        break;
            case 5:
	        // remove event
    		test.remove_event();
	        break;
            case 6:
	        // remove all
    		test.remove_all();
	        break;
            case 7:
	        // exit
    		test.finale();
	        break;
            default:
	        cout << "Not an option." << endl;
	        break;
        };
    } while (7 != response);

    return 0;
}
