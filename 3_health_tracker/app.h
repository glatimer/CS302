#include "BST.h"

/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
   	application.h will manage some dynamic binding pointers while pulling
	    together the BST, nodes, and hierarchy objects into 
	     a menu of items for the client to interact with.
   ........................................................................
   ------------------------------------------------------------------------ */
//using std::string;
//static int SIZE = 25;

class application
{
    public:
    application(void);
    ~application(void);
    int greeting(int option);
    int build_events(void);
    int display_events(void) const;
    int add_event(void);
    int edit_event(void);
    int complete_task(void) const;
    int remove_event(void);
    int remove_all(void);
    void finale(void) const;

    protected:
    BST tree;
    health_event *ptr;
    string title, date, time, dose;
    health_event *ptr1, *ptr2, *ptr3, *ptr4, *ptr5,
		 *ptr6, *ptr7, *ptr8, *ptr9, *ptr10,
		 *ptr11, *ptr12, *ptr13, *ptr14, *ptr15;
    int response;
};	
