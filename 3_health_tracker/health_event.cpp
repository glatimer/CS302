#include "health_event.h"
/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
       health_event.h will contain the prototypes and class members for
       our health_event hierarchy which will be used to make objects to 
     	 	populate a BST of scheduled health_events.
   ........................................................................
   ------------------------------------------------------------------------ */
using namespace std;

// default constructor
health_event::health_event(void)
{
    clear_members();
}

// param constructor
health_event::health_event(const string &TITLE, const string &DATE, 
	 		   const string &START)
{
    title = TITLE;
    date = DATE;
    start_time = START;
    response = 0;
    completed = false;
}

// destructor
health_event::~health_event(void)
{ 
    clear_members();
}

// assignment - health_event1 = health_event2
health_event& health_event::operator = (const health_event &source)
{
    // self assignment?
    if (this == &source) return *this;
    title = source.title;
    date = source.date;
    start_time = source.start_time;
    completed = source.completed;
    return *this;
}

// relational - evaluate total_time
bool health_event::operator < (const health_event &to_compare)
{
    // compare health_event's title with another
    if (title < to_compare.title) return true;
    
    // compare health_event date with another
    if (date < to_compare.date) return true;
    return false;
}


bool health_event::operator <= (const health_event &to_compare)
{
    // compare health_event's title with another
    if (title <= to_compare.title) return true;
    
    // compare health_event date with another
    if (date <= to_compare.date) return true;
    return false;
}

bool health_event::operator > (const health_event &to_compare)
{
    // compare health_event's title with another
    if (title > to_compare.title) return true;
    
    // compare health_event date with another
    if (date > to_compare.date) return true;
    return false;
}


bool health_event::operator >= (const health_event &to_compare)
{
    // compare health_event's title with another
    if (title >= to_compare.title) return true;
    
    // compare health_event date with another
    if (date >= to_compare.date) return true;
    return false;
}

// return the title of the health_event
string& health_event::get_title(void)
{
	return title;
}

// equality - compare make and model 
bool health_event::operator == (const health_event &to_compare) const
{
    return (title == to_compare.title &&
            date == to_compare.date &&
	    start_time == to_compare.start_time &&
	    completed == to_compare.completed);
}


bool health_event::operator != (const health_event &to_compare) const
{
    return (title != to_compare.title &&
            date != to_compare.date &&
	    start_time != to_compare.start_time &&
	    completed != to_compare.completed);
}

// standard functions
int health_event::schedule_event(void)
{
  //  string Title, Date, Start;
    cout << "Title: ";
    cin.ignore(100, '\n');
    getline(cin, title);

    cout << "Date: ";
    getline(cin, date);
//    date = Date;

    cout << "Start Time: ";
    getline(cin, start_time);
//    start_time = Start;
    return 1;
}

// clear the class members
int health_event::clear_members(void)
{
    title = "";
    date = "";
    start_time = "";
    response = 0;
    completed = false;
    return 0;
}

// compare by title or by date
bool health_event::compare(const string &to_find)
{
    if (title == to_find) return true;
    if (date == to_find) return true;
    return false;
}

// edit member data
int health_event::edit(void)
{
    cout << "Would you like to change: \n[1] Title \n[2] Date"; 
    cout << "\n[3] Start Time";
    return 0;
}

// display the members
int health_event::display(void)
{

   cout << endl << endl;
   cout << "Title: " << title << endl;
   cout << "Date: " << date << endl;
   cout << "Start Time: " << start_time << endl;
   cout << "Completed: " << std::boolalpha << completed << endl;
   return 1;
}

// pure virtual, not implemented here
//bool health_event::complete_task(void) {}


//celebrate when a task gets complete
int health_event::celebrate(void) 
{
    cout << ".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*." << endl
         << "                               WAY TO GO!  			" << endl
         << ".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*." << endl
         << "                                   .''.                                " << endl
         << "       .''.      .        *''*    :_\\/_:     .            .''.        " << endl
         << "      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\ :  .'.:.'.        :_\\/_:   " << endl
         << "  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=-  .''.  : /\\ :  . " << endl
         << " :_\\/_:'.:::.    ' *''*    * '.\\'/.' _\\(/_'.':'.' :_\\/_:'.:::. *   " << endl
         << " : /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  * : /\\ : ::::: * * " << endl
         << "  '..'  ':::'     * /\\ *     .'/.\\'.   '           '..'  ':::'  * . " << endl
         << "      *            *..*         :   *                     *            " << endl
         << "       *                             * 	                 *          " << endl
         << "        *	                      *                *                    " << endl
         << ".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*." << endl;
 
    return 0;
}



// int health_event::set_activity(void) {}

// .................................... FITNESS CLASS ....................................
// default constructor
fitness::fitness(void) 
{
    schedule_event();
}

// param constructor
fitness::fitness(const string &TITLE, const string &DATE, 
    const string &START, const fit_type &ACTIVE)
    : health_event(TITLE, DATE, START)
{
    activity = ACTIVE;
}


// destructor
fitness::~fitness(void) {}


// assignment - fitness1 = fitness2
fitness& fitness::operator = (const fitness &source)
{
    health_event::operator = (source);
    
    // self assignment?
    if (this == &source) return *this;

    activity = source.activity;
    
    return *this;
}

// standard functions
int fitness::schedule_event(void)
{
    cout << "\n___________________[FITNESS DATA]___________________" << endl;
    health_event::schedule_event();
    set_activity();

    // store data 
    fitness(title, date, start_time, activity);
    return 1;
}

// set data for activity enum
int fitness::set_activity(void)
{
    cout << "Choose Activity: \n[1] Strength Training \n[2] Cardio" 
         << "\n[3] Group Fitness \n[4] Adventure \n[5] Return" << endl;
    cout << "Selection: ";
    cin >> response;
    cin.ignore(100, '\n');
    switch (response)
    {
        // Strength Training
        case 1:
        { 
	    activity = STRENGTH;
	    break;
	}
	// Cardio
	case 2:
	{
	   activity = CARDIO;
	   break;
	}
	// Group Fitness
	case 3:
	{
	   activity = GROUP;
	   break;
	}
	// Adventure
	case 4:
	{
	   activity = ADVENTURE;
	   break;
	}
	default: 
	{
	   std::cerr << "Not an activity." << endl;
	   break;
	}
    };
    return 1;
}


// edit an object
int fitness::edit(void)
{
    cout << "\n___________________[FITNESS DATA]___________________" << endl;
    health_event::edit();
    cout << "\n[4] Activity \n[5] Return" << endl;
    cout << "Selection: ";
    cin >> response;
    cin.ignore(100, '\n');
    
    if (1 == response)
    {
        cout << "New Title: ";
	getline(cin, title);
    }
    else if (2 == response)
    {
        cout << "New Date: ";
	getline(cin, date);
    } 
    else if (3 == response)
    {
        cout << "New Start Time: ";
	getline(cin, start_time);
    }
    else if (4 == response)
    {
        set_activity();
    }
    else if (5 == response)
    {
        cout << "Back to options" << endl;
        return 2;
    }
    else
    {
        cout << "Not an option." << endl;
    }
    return 1;
}

// display an object
int fitness::display(void)
{
    health_event::display();
    cout << "Activity: ";

    switch (activity)
    {
       // Strength Training
       case 0:
       { 
	   cout << "Strength Training";
           break;
       }
       // Cardio
       case 1:
       {
	   cout << "Cardio";
           break;
       }
       // Group Fitness
       case 2:
       {
	   cout << "Group Fitness";
           break;
       }
       // Adventure
       case 3:
       {
	   cout << "Adventure";
           break;
       }
       default: 
       {
           std::cerr << "Not an activity." << endl;
           break;
       }
    };
    cout << endl;

    
    return 0;
}

// check off completed health_events
bool fitness::complete_task(void) 
{
    char choice;
    cout << "Did you finish your workout? (y/n): ";
    cin >> choice;
    cin.ignore(100, '\n');
    choice = toupper(choice);
    if ('Y' == choice) 
    {
        completed = true;
	celebrate();
	return true;
    }
    else if ('N' == choice) completed = false;
    else cout << "Not an option." << endl;
    return false;
}

// .................................... SUPPLEMENTS CLASS ....................................
// default constructor
supplements::supplements(void)
{
    schedule_event();
}


// param constructor
supplements::supplements(const string &TITLE, const string &DATE, 
	const string &START, const string &DOSE,
	const bool &WITH_FOOD)
	: health_event(TITLE, DATE, START)
{
    dose = DOSE;
    with_food = WITH_FOOD;
}


// destructor
supplements::~supplements(void)
{
    clear_members();
}

// assignment - health_event1 = health_event2
supplements& supplements::operator = (const supplements &source)
{
    health_event::operator = (source);
    
    // self assignment?
    if (this == &source) return *this;

    dose = source.dose;
    with_food = source.with_food;
    
    return *this;
}


// standard functions
int supplements::schedule_event(void)
{
    char choice;
    cout << "\n___________________[SUPPLEMENT DATA]___________________" << endl;
    health_event::schedule_event();
    cout << "Supplement Dose: ";
    getline(cin, dose);

    cout << "Take with food? (y/n): ";
    cin >> choice;
    cin.ignore(100, '\n');
    choice = toupper(choice);
    if ('Y' == choice) 
    {
        with_food = true;
	return true;
    }
    else if ('N' == choice) with_food = false;
    else cout << "Not an option." << endl;

    // store data 
    supplements(title, date, start_time, dose, with_food);
    return 0;
}

// clear the class members
int supplements::clear_members(void)
{
    dose = "";
    with_food = false;
    return 0;
}

// edit an object
int supplements::edit(void)
{
    char choice;
    cout << "\n___________________[SUPPLEMENTS DATA]___________________" << endl;
    health_event::edit();
    cout << "\n[4] Dose \n[5] Take with/without food \n[6] Complete Task \n[7] Return" << endl;
    cout << "Selection: ";
    cin >> response;
    cin.ignore(100, '\n');
    
    if (1 == response)
    {
        cout << "New Title: ";
	getline(cin, title);
//        cin >> title;
//        cin.ignore(100, '\n');
    }
    else if (2 == response)
    {
        cout << "New Date: ";
	getline(cin, date);
   //     cin >> date;
    //    cin.ignore(100, '\n');
    } 
    else if (3 == response)
    {
        cout << "New Start Time: ";
	getline(cin, start_time);
   //     cin >> start_time;
   //     cin.ignore(100, '\n');
    }
    else if (4 == response)
    {
        cout << "New Dose: ";
	getline(cin, dose);
   //     cin >> dose;
   //     cin.ignore(100, '\n');
    }
    else if (5 == response)
    {
        cout << "Take with food? (y/n): ";
        cin >> choice;
        cin.ignore(100, '\n');
        choice = toupper(choice);
        if ('Y' == choice) 
        {
            with_food = true;
	    return true;
        }
        else if ('N' == choice) with_food = false;
        else cout << "Not an option." << endl;
    }
    else if (6 == response)
    {
        complete_task();
    }
    else if (7 == response)
    {
        cout << "Back to options" << endl;
        return 2;
    }
    else
    {
        cout << "Not an option." << endl;
    }
    return 1;
}


// display an object
int supplements::display(void)
{
    health_event::display();
    cout << "Dose: " << dose << endl;
    cout << "With Food: " << std::boolalpha << with_food << endl;
    return 0;
}

// flag an item completed
bool supplements::complete_task(void)
{
    char choice;
    cout << "Did you take your supplements? (y/n): ";
    cin >> choice;
    cin.ignore(100, '\n');
    choice = toupper(choice);
    if ('Y' == choice) 
    {
        completed = true;
	celebrate();
	return true;
    }
    else if ('N' == choice) completed = false;
    else cout << "Not an option." << endl;
    return false;
}

/*
// celebrate the wins!!
int supplements::celebrate(void)
{
    return 0;
}
*/  

// .................................... INTERMITTENT FASTING CLASS .................................... 
// default constructor
IF::IF(void)
{
    schedule_event();
}


// param constructor
IF::IF(const string &TITLE, const string &DATE, 
       const string &START, const int DURATION)
       : health_event(TITLE, DATE, START)	
{
    duration = DURATION;
    fast = false;
}


// destructor
IF::~IF(void)
{
    clear_members();
}

// assignment - IF1 = IF2
IF& IF::operator = (const IF &source)
{
    health_event::operator = (source);
    
    // self assignment?
    if (this == &source) return *this;

    duration = source.duration;
    return *this;
}

// standard functions
int IF::schedule_event(void)
{
    cout << "\n_______________[INTERMITTENT FASTING DATA]_______________" << endl;
    health_event::schedule_event();
    cout << "How long are you planning to fast?";
    cout << "[1] 16 hour fast" << endl;
    cout << "[2] 20 hour fast" << endl;
    cout << "[3] 24 hour fast" << endl;
    cout << "Selection: ";
    cin >> response;
    cin.ignore(100, '\n');

    if (1 == response)
    {
        duration = 16;
	window = BEGINNER;
    }
    else if (2 == response)
    {
        duration = 20;
	window = MODERATE;
    }
    else if (3 == response)
    {
        duration = 24;
	window = ADVANCED;
    }
    // store data 
    IF(title, date, start_time, duration);
    return 0;
}

// clear the class members
int IF::clear_members(void)
{
    duration = 0;
    fast = false;
    return 0;
}


// edit an object
int IF::edit(void)
{
    cout << "\n___________________[INTERMITTENT FASTINGS DATA]___________________" << endl;
    health_event::edit();
    cout << "\n[4] Fasting Window \n[5] Return" << endl;
    cout << "Selection: ";
    cin >> response;
    cin.ignore(100, '\n');
    
    if (1 == response)
    {
        cout << "New Title: ";
//        cin.ignore(100, '\n');
	getline(cin, title);
        //cin >> title;

    }
    else if (2 == response)
    {
        cout << "New Date: ";
//        cin >> date;
	getline(cin, date);
//        cin.ignore(100, '\n');
    } 
    else if (3 == response)
    {
        cout << "New Start Time: ";
	getline(cin, start_time);
       // cin >> start_time;
       // cin.ignore(100, '\n');
    }
    else if (4 == response)
    {
        cout << "\nHow long are you planning to fast?" << endl;
        cout << "[1] 16 hour fast : 8 hour feed" << endl;
        cout << "[2] 20 hour fast : 4 hour feed" << endl;
        cout << "[3] 24 hour fast" << endl;
        cout << "Selection: ";
        cin >> response;
        cin.ignore(100, '\n');

        if (1 == response)
        {  
            duration = 16;
	    window = BEGINNER;
        }
        else if (2 == response)
        {
            duration = 20;
	    window = MODERATE;
        }
        else if (3 == response)
        {
            duration = 24;
	    window = ADVANCED;
        }
    } 
    else if (5 == response)
    {
        complete_task();
    }
    else if (6 == response)
    {
        cout << "Back to options" << endl;
        return 2;
    }
    else
    {
        cout << "Not an option." << endl;
    }
    return 0;
}


// display an object
int IF::display(void)
{
    string IF_window = " ";
    health_event::display();

    if (window == BEGINNER)
    {
        IF_window = "16:8";
    }
    else if (window == MODERATE)
    {
        IF_window = "20:4";
    }
    else if (window == ADVANCED)
    {
        IF_window = "24:0";
    }
    cout << "Fasting Window: " << IF_window << endl;
    cout << "Duration: " << duration << endl;
    cout << "Currently Fasting: " << std::boolalpha << fast << endl;
    return 0;
}

// flag an item completed
bool IF::complete_task(void)
{
    char choice;
    cout << "Did you complete your fast? (y/n): ";
    cin >> choice;
    cin.ignore(100, '\n');
    choice = toupper(choice);
    if ('Y' == choice) 
    {
        completed = true;
	celebrate();
	return true;
    }
    else if ('N' == choice) completed = false;
    else cout << "Not an option." << endl;
    return false;
}

/*
// celebrate the wins!!
int IF::celebrate(void)
{
    return 0;
}
*/

// start a countdown when the fasting window begins
/*
int IF::countdown(void)
{
    return 0;
}
*/

// alert when the fasting window is over
int IF::alert(void)
{
    cout << "\nYou did it! Youre fasting window is complete.\n" << endl;
    celebrate();
    return 0;
}

