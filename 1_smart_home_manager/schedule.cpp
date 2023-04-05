#include "schedule.h"
/* ===============================================================================
                       CS302 Assignment 1 - Genevieve Latimer
   -------------------------------------------------------------------------------
         features.cpp will contain the implementation of classes defined
       			      in the features.h file.
   =============================================================================== */
using namespace std;

/*
string title;
string DOW;
string start_time;
string finish_time;
*/
// .................................. SHEDULE ..................................
// smart_thermostat will implement the use of an ARR_LLL containing 
// a collection of schedules
schedule::schedule()
{
    clear_members();
}

// param constructor
schedule::schedule(const string &a_title, const int a_DOW, 
	   	  const string &to_start, const string &to_finish)
{
    title = a_title;
    DOW = a_DOW;
    start_time = to_start;
    finish_time = to_finish;
}

// destructor
schedule::~schedule()
{
    clear_members();
}

int schedule::display(void)
{
    cout << "Title: " << title << endl;
    cout << "Day: " << DOW << endl;
    cout << "Start: " << start_time << endl;
    cout << "Finish: " << finish_time << endl;
    return 0;
}

int schedule::clear_members(void)
{
    title = ' ';
    DOW = ' ';
    start_time = ' ';
    finish_time = ' ';
    return 0;
}

//................................... NODE ........................................
// the thermostat device will have an array of linked lists
// containing schedule objects to simulate a preset feature
// a node that is a schedule PLUS MORE!
// default constructor
NODE::NODE()
{
    next = nullptr;
}

// destructor
NODE::~NODE()
{
    next = nullptr;
}

// param constructor
NODE::NODE(const schedule &new_schedule)
           : schedule(new_schedule)
{
    next = nullptr;
}

// copy constructor
NODE::NODE(const NODE &to_copy)
	   : schedule(to_copy)
{
}

// assignment operator
NODE& NODE::operator=(const NODE & input)
{
    return *this;
}

// setter
void NODE::set_next(NODE * new_next)
{
    next = new_next;
}

//getter
NODE *& NODE::get_next()
{
    return next;
}

// ................................... ARRAY OF LINKED LISTS ..................................
// default constructor
ARR_LLL::ARR_LLL(int size)
{
    head_arr = new NODE*[size];
    arr_size = size;
    DAY = ' ';
    for (int i = 0; i < arr_size; ++i)
    {
        head_arr[i] = nullptr;
    }
}

// destructor
ARR_LLL::~ARR_LLL()
{
    // node for traversal
    NODE *curr = nullptr;
    NODE *temp = nullptr;

    // iterate through the array
    for (int i = 0; i < arr_size; ++i)
    {
        while (head_arr[i])
	{
	    temp = head_arr[i];
	    curr = temp->get_next();
	    delete temp;
	    temp = curr;
	}
	head_arr[i] = nullptr;
	arr_size = 0;
    }
}

/*
// copy constructor
ARR_LLL::ARR_LLL(const ARR_LLL &to_copy)
{
}
*/

// add at item to the ARR_LLL
int ARR_LLL::insert(const NODE &to_add)
{
    // add first element
    return 0;
}

// display one item 
int ARR_LLL::display(const string &a_DOW)
{
    return 0;
}

// display all items 
int ARR_LLL::display_all(void) const
{
    return 0;
}

// remove one item
int ARR_LLL::remove(const string &to_remove)
{
    return 0;
}

// remove all items
int ARR_LLL::remove_all(void) const
{
    return 0;
}
