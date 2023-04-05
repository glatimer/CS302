#include "app.h"
/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
    application.cpp will implement the functions for our client experience
   ........................................................................
   ------------------------------------------------------------------------ */
using namespace std;

/*
BST tree;
health_event* ptr;
char choice;
int response;
*/
application::application(void)
{
    ptr = ptr1 = ptr2 = ptr3 = ptr4 = ptr5 = ptr6 = ptr7 = ptr8 = nullptr;
    ptr9 = ptr10 = ptr11 = ptr12 = ptr13 = ptr14 = ptr15 = nullptr;
    response = 0;
    title = " ";
    date = " ";
    time = " ";
}

application::~application(void)
{
    if (ptr1) delete ptr1;
    if (ptr2) delete ptr2;
    if (ptr3) delete ptr3;
    if (ptr4) delete ptr4;
    if (ptr5) delete ptr5;
    if (ptr6) delete ptr6;
    if (ptr7) delete ptr7;
    if (ptr8) delete ptr8;
    if (ptr9) delete ptr9;
    if (ptr10) delete ptr10;
    if (ptr11) delete ptr11;
    if (ptr12) delete ptr12;
    if (ptr13) delete ptr13;
    if (ptr14) delete ptr14;
    if (ptr15) delete ptr15;
    if (ptr) delete ptr;
    ptr = nullptr;
    response = 0;
    title = " ";
    date = " ";
    time = " ";
}

int application::greeting(int option)
{
    if (1 == option)
    {
        cout << "*----------------------------------------------------------------------*\n"
             << "|                       HEALTHY HABIT PLANNER                          |\n"
             << "*________.________._________.___________.__________.________.__________*\n" 
             << "| Sunday | Monday | Tuesday | Wednesday | Thursday | Friday | Saturday |\n" 
             << "*--------+--------+---------+-----------+----------+--------+----------*\n" 
             << "|    ✔   |    ✔   |     ✔   |      ✔    |     ✔    |    ✔   |     ✔    |\n" 
             << "*----------------------------------------------------------------------*" << endl; 
	 return 1;
    }
    else if (2 == option)
    {
        cout << "*----------------------------------------------------------------------*" << endl;
	cout << "|                              MAIN MENU                               |" << endl;
        cout << "*----------------------------------------------------------------------*" << endl
	     << "\n[1] Add An Event \n[2] Display List of Events \n[3] Edit An Event"
	     << "\n[4] Complete An Event \n[5] Remove An Event \n[6] Remove All Events" 
	     << "\n[7] Exit \n"
	     << "Selection: ";
        cin >> response;
        cin.ignore(100, '\n');
        return response;
    }
    else 
    {
        return 0;
    }
}


int application::build_events(void)
{
    title = "Hike at Mt. Hood";
    date = "5/25/2023";
    time = "6:45am";
    health_event* ptr1 = new fitness(title, date, time, ADVENTURE);
    date = "4/25/2023";
    health_event *ptr2 = new fitness(title, date, time, ADVENTURE);
    date = "6/25/2023";
    health_event *ptr3 = new fitness(title, date, time, ADVENTURE);
    title = "Vitamin D";
    date = "Weekly";
    time = "Fridays";
    string dose = "7,000 IU";
    health_event *ptr4 = new supplements(title, date, time, dose, false);
    title = "Week 1";
    date = "3/6/2023";
    time = "6:00pm";
    health_event *ptr5 = new IF(title, date, time, 16);
    date = "3/8/2023";
    health_event *ptr6 = new IF(title, date, time, 16);
    date = "3/10/2023";
    health_event *ptr7 = new IF(title, date, time, 20);
    title = "Yoga Class";
    date = "Tuesdays";
    time = "6:30am";
    health_event *ptr8 = new fitness(title, date, time, GROUP);
    title = "Barre Class";
    date = "Thursdays";
    time = "4:40pm";
    health_event *ptr9 = new fitness(title, date, time, GROUP);
    title = "Cod Liver Oil";
    date = "daily";
    time = "10:00p";
    dose = "2 Tablespoons";
    health_event *ptr10 = new supplements(title, date, time, dose, false);
    title = "Electrolytes";
    date = "Monday, Wednesday, Friday";
    time = "7:00a";
    dose = "16 ounces";
    health_event *ptr11 = new supplements(title, date, time, dose, false);
    title = "Week 2";
    date = "3/13/2023";
    time = "6:00pm";
    health_event *ptr12 = new IF(title, date, time, 16);
    date = "3/15/2023";
    health_event *ptr13 = new IF(title, date, time, 16);
    date = "3/17/2023";
    health_event *ptr14 = new IF(title, date, time, 24);
    title = "Swimming";
    date = "Sundays";
    time = "10:00a";
    health_event *ptr15 = new fitness(title, date, time, CARDIO);

    tree.insert(ptr1);
    tree.insert(ptr2);
    tree.insert(ptr3);
    tree.insert(ptr4);
    tree.insert(ptr5);
    tree.insert(ptr6);
    tree.insert(ptr7);
    tree.insert(ptr8);
    tree.insert(ptr9);
    tree.insert(ptr10);
    tree.insert(ptr11);
    tree.insert(ptr12);
    tree.insert(ptr13);
    tree.insert(ptr14);
    tree.insert(ptr15);

    return 15;
}

int application::display_events(void) const
{
    cout << "\n-----------------------------------------------------------------------" << endl;
    cout << "......................................................................." << endl;
    cout << "                            CALENDAR OF EVENTS                           " << endl;
    cout << "......................................................................." << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    int count = tree.display();
    if (count)
    {
        cout << "There are " << count << " events on the calendar." << endl;
    }
    else
    {
        cout << "\n\n*----------------------------------------------------------------------*" << endl;
	cout << "                         The calendar is empty.                           " << endl;
        cout << "*----------------------------------------------------------------------*\n\n" << endl;
    }
    return count;
}

int application::add_event(void)
{
    int choice = 0;
    int count = 0;
    do
    {
        cout << "\n-----------------------------------------------------------------------" << endl;
	cout << "                            ADD A NEW EVENT                              " << endl;
        cout << "-----------------------------------------------------------------------\n" << endl;
	cout << "[1] Fitness" << endl
	     << "[2] Supplements" << endl
	     << "[3] Intermittent Fasting" << endl
	     << "[4] Back to Main Menu" << endl;
	cout << "Selection: ";
	cin >> choice;

	switch (choice) 
	{
	    case 1: 
   	    {
		ptr = new fitness();
		tree.insert(ptr);
		++count;
		break;
	    }
  	    case 2: 
	    {
		ptr = new supplements();
		tree.insert(ptr);
		++count;
		break;
	    }
	    case 3: 
	    {
		ptr = new IF();
		tree.insert(ptr);
		++count;
		break;
	    }
	}
    } while (choice > 0 && choice < 4);
    
    return count;
}

int application::edit_event(void)
{
    cout << "\n-----------------------------------------------------------------------" << endl;
    cout << "                              EDIT EVENT                               " << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    cout << "What event would you like to edit?" << endl;
    cout << "Answer: ";
    getline(cin, title);

    tree.edit_data(title);
    return 0;
}

int application::complete_task(void) const
{
    string Title;
    cout << "\n-----------------------------------------------------------------------" << endl;
    cout << "                             COMPLETE TASK                             " << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    cout << "What event would you like to complete?" << endl;
    cout << "Answer: ";
    getline(cin, Title);
    
    int result = const_cast<BST&>(tree).complete_task(Title);
    
    // exception handling 
    try
    {
        if (2 != result)
	{
	    throw(result);
	}
	else
        {
	    // upcasting
	    IF *temp_ptr = dynamic_cast<IF*>(ptr);
	    if (temp_ptr) temp_ptr->alert();
	}
    } catch (int num)
    {
        cerr << "Alert function is for IF derived only." << endl;
    }
    return 0;
}

int application::remove_event(void)
{
    cout << "\n-----------------------------------------------------------------------" << endl;
    cout << "                              REMOVE EVENT                               " << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    cout << "What event would you like to remove?" << endl;
    cout << "Answer: ";
    getline(cin, title);
    tree.remove(title);
    return 0;
}

int application::remove_all(void)
{
    int count = tree.remove_all();
    return count;
}

void application::finale(void) const
{
    cout << ".........................Thank you for using ..........................." << endl;
    cout << "*----------------------------------------------------------------------*\n"
         << "|                       HEALTHY HABIT PLANNER                          |\n"
         << "*________.________._________.___________.__________.________.__________*\n" 
         << "| Sunday | Monday | Tuesday | Wednesday | Thursday | Friday | Saturday |\n" 
         << "*--------+--------+---------+-----------+----------+--------+----------*\n" 
         << "|    ✔   |    ✔   |     ✔   |      ✔    |     ✔    |    ✔   |     ✔    |\n" 
         << "*----------------------------------------------------------------------*" << endl;
    cout << "                          See You Tomorrow!                             " << endl;
}



