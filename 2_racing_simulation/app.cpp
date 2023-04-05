#include "app.h"
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
	   function implementation for client code in main().
   if there is time, we can choose contestants, display roster, and 
    remove constestants.  For now we will prefill some contestants, 
   	     give the option to add, and simulate the race
----------------------------------------------------------------------- */

using namespace std;

// default constructor
app::app(void): option(0) {}

// destructor
app::~app(void) 
{
    option = 0; 
}

// greeting
void app::greeting(void)
{
    cout << "________________________________________________________________________" << endl; 
    cout << "   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||" << endl;
    cout << "|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   ||    " << endl;
    cout << "   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                        Get Ready to Race!!!                            " << endl;
    cout << "------------------------------------------------------------------------\n" << endl;
    cout << "\n(1) Gambler 500 Racing\n(2) Electric Vehicle Racing"
         << "\n(3) Mario Kart Racing \n(4) Quit" << endl;
}


// MENU 1 option
int app::choose_race(const int &choice)
{
    // build race track events
    build_race();

    switch (choice)
    {
        // Gambler 500 
        case 1:
        {
	    // variables
	    DLL <gambler_500> roster;
	    
	    // prefill a roster of contestants
	    build_roster(roster);
	    
	    // menu options
	    do {
	        cout << "----------------------------------------------------------------" << endl;
	        cout << "               WELCOME TO THE 2023 GAMBLER 500!                 " << endl;
	        cout << "----------------------------------------------------------------" << endl;
	        cout << "\n(1) Add a Contestant\n(2) Display Roster" 
	  	     << "\n(3) Start the Race!\n(4) Quit" << endl;
	        cout << "What would you like to do: ";
	        cin >> option;
	        cin.ignore(100, '\n');

	        // add a contestant
	        if (option == 1)
	        {
	            add_contestant(roster);
	        }
		// display contestants
	        if (option == 2)
	        {
	    	    roster.display();
	        }
		// I prepopulated the race contestants.  Ideally, I would have liked to give the option 
		// to load in three contestants from the DLL and then run the race
		if (option == 3)
		{
		    gambler_500 d1 = gambler_500("Chevrolet", "Bronco", 2, 499.99, 6180, 1993, "All Wheel Drive");
		    gambler_500 d2 = gambler_500("Honda", "Civic", 3, 475.85, 2405, 2002, "Two Wheel Drive");
		    gambler_500 d3 = gambler_500("Toyota", "Celica", 1, 255.50, 2425, 2005, "Two Wheel Drive");
		    start_race(d1, d2, d3);
		}
	    } while (option != 4);
	    break;
	}
        case 2:
        {
	    // variables
	    DLL <electric_car> roster;

	    // prefill a roster of contestants
	    build_roster(roster);

	    // menu options
	    do {
	        cout << "----------------------------------------------------------------" << endl;
	        cout << "          WELCOME TO THE 2023 ELECTRIC VEHICLE RACE!            " << endl;
	        cout << "----------------------------------------------------------------" << endl;
	        cout << "\n(1) Add a Contestant\n(2) Display Roster" 
	  	     << "\n(3) Start the Race (demo)!\n(4) Quit" << endl;
	        cout << "What would you like to do: ";
	        cin >> option;
	        cin.ignore(100, '\n');

	        // add a contestant
	        if (option == 1)
	        {
	            add_contestant(roster);
	        }
		// display contestants
	        if (option == 2)
	        {
	    	    roster.display();
	        }
		// I prepopulated the race contestants.  Ideally, I would have liked to give the option 
		// to load in three contestants from the DLL and then run the race
		if (option == 3)
		{
		    electric_car d1 = electric_car("Rimac", "C_Two", 4, 5);
		    electric_car d2 = electric_car("Tesla", "Model S", 3, 7);
		    electric_car d3 = electric_car("Pininfarina", "Battista", 1, 6); 
		    start_race(d1, d2, d3); 
		}
	    } while (option != 4);

	    break;
	}
        case 3:
        {
	    // variables
	    DLL <mario_kart> roster;
	    
	    // prefill roster with contestants
	    build_roster(roster);

	    do 
	    {
	        cout << "----------------------------------------------------------------" << endl;
	        cout << "          WELCOME TO THE 2023 MARIO KART CHAMPIONSHIP           " << endl;
	        cout << "----------------------------------------------------------------" << endl;
	        cout << "\n(1) Add a Contestant\n(2) Display Roster" 
	  	     << "\n(3) Start the Race!\n(4) Quit" << endl;
	        cout << "What would you like to do: ";
	        cin >> option;
	        cin.ignore(100, '\n');

	        // add a contestant
	        if (option == 1)
	        {
	            add_contestant(roster);
	        }
		// display contestants
	        if (option == 2)
	        {
	    	    roster.display();
	        }
		// I prepopulated the race contestants.  Ideally, I would have liked to give the option 
		// to load in three contestants from the DLL and then run the race
		if (option == 3)
		{
		    mario_kart d1 = mario_kart("Mario Kart", "Mario", 10);
		    mario_kart d2 = mario_kart("Luigi Buggy", "Luigi", 10);
		    mario_kart d3 = mario_kart("Peach Pit", "Peach", 9); 
		    start_race(d1, d2, d3); 
		}
	    } while (option != 4);

	    break;
	  }
	  default:
	  {
	      cout << "Not an option!" << endl;
	      break;
	  }
     }
     return 0;
}

// build a list of contestants
template <typename TYPE>
int app::build_roster(DLL <TYPE> &roster)
{
    // if TYPE == gambler_500
    if constexpr (is_same<TYPE, gambler_500>::value)
    {
        gambler_500 driver_1 = gambler_500("Chevrolet", "Bronco", 2, 499.99, 6180, 1993, "All Wheel Drive");
        gambler_500 driver_2 = gambler_500("Honda", "Civic", 3, 475.85, 2405, 2002, "Two Wheel Drive");
        gambler_500 driver_3 = gambler_500("Toyota", "Celica", 1, 255.50, 2425, 2005, "Two Wheel Drive");
        gambler_500 driver_4 = gambler_500("Ford", "Explorer", 2, 285.00, 4460, 2010, "All Wheel Drive");
        gambler_500 driver_5 = gambler_500("Subaru", "Outback", 3, 499.00, 3160, 1999, "All Wheel Drive");
	roster.insert(driver_1);
	roster.insert(driver_2);
	roster.insert(driver_3);
	roster.insert(driver_4);
	roster.insert(driver_5);
    }
    // if TYPE == electric_car
    else if constexpr (is_same<TYPE, electric_car>::value)
    {
        electric_car driver_1 = electric_car("Rimac", "C_Two", 4, 5);
        electric_car driver_2 = electric_car("Tesla", "Model S", 3, 7);
        electric_car driver_3 = electric_car("Pininfarina", "Battista", 1, 6); 
        electric_car driver_4 = electric_car("NIO", "EP9", 2, 8); 
        electric_car driver_5 = electric_car("Porsche", "Taycan", 3, 5); 
	roster.insert(driver_1);
	roster.insert(driver_2);
	roster.insert(driver_3);
	roster.insert(driver_4);
	roster.insert(driver_5);
    }
    // if TYPE == mario_kart
    else if constexpr (is_same<TYPE, mario_kart>::value)
    {
        mario_kart driver_1 = mario_kart("Mario Kart", "Mario", 10);
        mario_kart driver_2 = mario_kart("Luigi Buggy", "Luigi", 10);
        mario_kart driver_3 = mario_kart("Peach Pit", "Peach", 9); 
        mario_kart driver_4 = mario_kart("Yoshi Egg", "Yoshi", 5); 
        mario_kart driver_5 = mario_kart("Wario Brute", "Wario", 18); 
	roster.insert(driver_1);
	roster.insert(driver_2);
	roster.insert(driver_3);
	roster.insert(driver_4);
	roster.insert(driver_5);
    } 
    else
    {
        cerr << "Type not supported." << endl;
    }
    return 0;
}
    

template <typename TYPE>
int app::add_contestant(DLL <TYPE> &roster)
{
    char make[SIZE];
    string model;
    int experience;
        
    cout << "What is the make of your gambler? ";
    cin.get(make, 100, '\n');
    cin.ignore(100, '\n');

    cout << "What is the model of your gambler? ";
    cin >> model;
	
    cout << "How many years have you attended Gambler 500? ";
    cin >> experience;
    cin.ignore(100, '\n');
    
    // if adding a gambler
    if constexpr (is_same<TYPE, gambler_500>::value)
    {
	double price;
	double lbs;
	int year;
	char drivetrain[SIZE];
	
	cout << "What year is your gambler? ";
	cin >> year;
	cin.ignore(100, '\n');
	
	cout << "How much does your gambler weigh? ";
	cin >> lbs;
	cin.ignore(100, '\n');

	cout << "How much did you buy it for? ";
	cin >> price;
	cin.ignore(100, '\n');

	cout << "What style of drivetrain is your gambler? ";
	cin.get(drivetrain, 100, '\n');
	cin.ignore(100, '\n');

        gambler_500 driver = gambler_500(make, model, experience, price, lbs, year, drivetrain);
	roster.insert(driver);
    }
    // if adding an electric
    else if constexpr (is_same<TYPE, electric_car>::value)
    {
        int charge {0};

	cout << "Rate Charge Frequency (range: worst 1-10 best): ";
	cin >> charge;
	cin.ignore(100, '\n');

        electric_car driver = electric_car(make, model, experience, charge);
	roster.insert(driver);
    }
    // if adding a mario
    else if constexpr (is_same<TYPE, mario_kart>::value)
    {
        mario_kart driver = mario_kart(make, model, experience);
	roster.insert(driver);
        
    }
    return 0;

}

// Ideally there would be an option to 
// add your own obstacle courses in any 
// desired order
// this one is a preset the race course
int app::build_race(void)
{
    // ugly way to populate the race_course
    string title1 = "Starting Line";
    event_type one = START;  
    event obstacle1 = event(title1, one);

    string title2 = "Bend in the Road";
    event_type two = COLLISION; 
    event obstacle2 = event(title2, two);

    string title3 = "Swamp Land"; 
    event_type three = TREE_DOWN; 
    event obstacle3 = event(title3, three);

    string title4 = "Underground Caves"; 
    event_type four = ROCKS_FALLING; 
    event obstacle4 = event(title4, four);

    string title5 = "Open Plain";
    event_type five = COLLISION; 
    event obstacle5 = event(title5, five);

    string title6 = "Power Strip";
    event_type six = POWER_STRIP; 
    event obstacle6 = event(title6, six);

    string title7 = "Forest"; 
    event_type seven = TREE_DOWN; 
    event obstacle7 = event(title7, seven);

    string title8 = "Opponent"; 
    event_type eight = COLLISION; 
    event obstacle8 = event(title8, eight);

    string title9 = "Up Hill Climb"; 
    event_type nine = ROCKS_FALLING; 
    event obstacle9 = event(title9, nine);

    string title10 = "Finish Line";
    event_type ten = FINISH; 
    event obstacle10 = event(title10, ten);
 
    // add events to the race_course list
    race_course.push_front(obstacle10);
    race_course.push_front(obstacle9);
    race_course.push_front(obstacle8);
    race_course.push_front(obstacle7);
    race_course.push_front(obstacle6);
    race_course.push_front(obstacle5);
    race_course.push_front(obstacle4);
    race_course.push_front(obstacle3);
    race_course.push_front(obstacle2);
    race_course.push_front(obstacle1);

/*
    // display event forward_list
    for (auto &interaction : race_course)
    {
        interaction.display();
	cout << endl;
    }
*/
    return 0;
}

// simulate the race for any TYPE
// generic programming!
template <typename TYPE>
int app::start_race(TYPE &d1, TYPE &d2, TYPE &d3)
{
    // simulate the race
    cout << "\nCONTESTANT No. ONE!" << endl;
    int score_1 = d1.simulate_race(race_course);

    cout << "\nCONTESTANT No. TWO!" << endl;
    int score_2 = d2.simulate_race(race_course);
    
    cout << "\nCONTESTANT No. THREE!" << endl;
    int score_3 = d3.simulate_race(race_course);
    
    // find smallest time
    vector <int> scores = {score_1, score_2, score_3};
    int winner = *min_element(scores.begin(), scores.end());

    // display results
    if (winner == score_1)
    {
	finale(1);
	cout << "............................" << endl;
	cout << "           WINNER!      " << endl;
	cout << "............................" << endl;
	cout << d1;
	cout << "............................" << endl;
	cout << d2;
	cout << endl;
	cout << d3;
	cout << endl;
	finale(2);
    }
    else if (winner == score_2)
    {
	cout << "............................" << endl;
	cout << "           WINNER!      " << endl;
	cout << "............................" << endl;
	cout << d1;
	cout << "............................" << endl;
	cout << d2;
	cout << endl;
	cout << d3;
	cout << endl;
    }
    else if (winner == score_3)
    {
	cout << "............................" << endl;
	cout << "           WINNER!      " << endl;
	cout << "............................" << endl;
	cout << d3;
	cout << "............................" << endl;
	cout << d1;
	cout << endl;
	cout << d2;
	cout << endl;
    }
    else
    {
	cerr << "No winner." << endl;
    }
    return 0;
}

// display the list of contestants
template <typename TYPE>
int app::display_roster(const DLL<TYPE> &roster)
{
    return roster.display();
}

// formatting for closing display
void app::finale(const int option)
{
    // top banner
    if (1 == option)
    {
        cout << "________________________________________________________________________" << endl; 
        cout << "   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||" << endl;
	cout << "|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   ||    " << endl;
        cout << "   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "                          WE HAVE A WINNER!!!                           " << endl;
        cout << "------------------------------------------------------------------------\n" << endl;
    }
    // bottom banner
    else if (2 == option)
    {
	cout << "------------------------------------------------------------------------" << endl;
	cout << "                       Thanks for Racing with Us                        " << endl;
	cout << "________________________________________________________________________" << endl; 
	cout << "   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||" << endl;
	cout << "|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   ||    " << endl;
	cout << "   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||" << endl;
	cout << "------------------------------------------------------------------------" << endl;
    }
}

