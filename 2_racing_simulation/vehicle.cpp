#include "vehicle.h"
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
vehicle.cpp is where the heirarchy of class objects will be implemented.
----------------------------------------------------------------------- */

using namespace std;

// ============================== VEHICLE ==============================
// default constructor
vehicle::vehicle(void)
{
    make = nullptr;
    model = ' ';
    total_time = 0; 	
    driver_experience = 0;  // in years
}

// param constructor
vehicle::vehicle(const char *MAKE, const string &MODEL,
    		 const int &EXPERIENCE)
{
    // exception handling
    try
    {
        make = new char[strlen(MAKE) + 1];
        strcpy(make, MAKE);
    }
    catch (std::bad_alloc& exception)
    {
	cerr << "Bad Alloc Detected: " << exception.what();
    }  

    model = MODEL;
    total_time = 0;  // doesn't start until *go*
    driver_experience = EXPERIENCE;
}

// destructor
vehicle::~vehicle(void)
{
    if (make) delete [] make;
    make = nullptr;
    model = ' ';
    total_time = 0;
    driver_experience = 0;
}

// copy constructor
vehicle::vehicle(const vehicle &to_copy)
{
    if (to_copy.make)
    {
        // exception handling
        try
	{
            make = new char[strlen(to_copy.make) + 1];
            strcpy(make, to_copy.make);
	}
        catch (std::bad_alloc& exception)
        {
 	    cerr << "Bad Alloc Detected: " << exception.what();
        }  

        model = to_copy.model;
        total_time = 0;
        driver_experience = to_copy.driver_experience;
    }
}

// assignment - vehicle1 = vehicle2
vehicle vehicle::operator = (const vehicle &src)
{
    // self assignment?
    if (this == &src) return *this;

    // delete memory
    if (make) delete [] make;

    make = new char[strlen(src.make) + 1];
    strcpy(make, src.make);
    model = src.model;
    total_time = 0;  // doesn't start until *go*
    driver_experience = src.driver_experience;
    return src;
}

// relational - compare driver experiences or total_time
bool vehicle::operator <  (const vehicle &to_compare)
{
    // compare driver's experience with another
    if (driver_experience < to_compare.driver_experience) return true;
    // compare vehicle total_time with another
    if (total_time < to_compare.total_time) return true;
    return false;
}

// relational - compare driver experiences or total_time
bool vehicle::operator <= (const vehicle &to_compare)
{
    // compare driver's experience with another
    if (driver_experience <= to_compare.driver_experience) return true;
    // compare vehicle total_time with another
    if (total_time <= to_compare.total_time) return true;
    return false;
}

// relational - compare driver experiences or total_time
bool vehicle::operator >  (const vehicle &to_compare)
{
    // compare driver's experience with another
    if (driver_experience > to_compare.driver_experience) return true;
    // compare vehicle total_time with another
    if (total_time > to_compare.total_time) return true;
    return false;
}

// relational - compare driver experiences or total_time
bool vehicle::operator >= (const vehicle &to_compare)
{
    // compare driver's experience with another
    if (driver_experience >= to_compare.driver_experience) return true;
    // compare vehicle total_time with another
    if (total_time >= to_compare.total_time) return true;
    return false;
}

// equality - compare make and model 
bool vehicle::operator == (const vehicle &to_compare) const
{
    return (make == to_compare.make && 
    	    model == to_compare.model &&
	    total_time == to_compare.total_time && 	// not sure if I want to include this member cmp
	    driver_experience == to_compare.driver_experience);
}

// equality - compare make and model 
bool vehicle::operator != (const vehicle &to_compare) const
{
    return (make != to_compare.make && 
    	    model != to_compare.model &&
	    total_time != to_compare.total_time && 	// not sure if I want to include this member cmp
	    driver_experience != to_compare.driver_experience);
}

// I/O - cin new vehicle contents, cout vehicle display
// client side will have to build and populate a vehicle object 
// then pass it in as an argument through >> operator
// cin new vehicle contents
istream & operator >> (istream &input, vehicle &to_add)
{
    // the only way to be able to overload AND use this operator
    // is to be able to prompt the user from within the operator

    char *temp; 
    if (to_add.make)
    {
        // exception handling
	try
	{
	    temp = new char[strlen(to_add.make) + 1];
	    strcpy(temp, to_add.make);
	}
        catch (std::bad_alloc& exception)
        {
	    cerr << "Bad Alloc Detected: " << exception.what();
        }  
    }
    input >> temp;
    input >> to_add.model;
    input >> to_add.total_time;
    input >> to_add.driver_experience;
    return input;
}

// the << operator will display a vehicle object
// cout vehicle display
ostream & operator << (ostream &output, const vehicle &to_display)
{
    //make = new char[strlen(src.make) + 1];
    //strcpy(make, src.make);
    // the only way to be able to overload AND use this operator
    // is to add formatting for display

    char *temp; 
    if (to_display.make)
    {
        // exception handling
	try
	{
	    temp = new char[strlen(to_display.make) + 1];
	    strcpy(temp, to_display.make);
	}
        catch (std::bad_alloc& exception)
        {
	    cerr << "Bad Alloc Detected: " << exception.what();
        }  
    }
    output << "Make: " << temp << endl;
    output << "Model: " << to_display.model << endl;
    output << "Time: " << to_display.total_time/60 << " minutes" << endl;
    output << "Experience: " << to_display.driver_experience << endl;
    return output;
}

// arithmetic - add boost of total_time?
vehicle vehicle::operator +  (const vehicle &to_add)
{
    vehicle temp = *this;
    temp.total_time += to_add.total_time;
    return temp;
}

// arithmetic - add boost of total_time?
vehicle& vehicle::operator += (const vehicle &to_add)
{
    total_time += to_add.total_time;
    return *this;
}

// ============================== GAMBLER 500 ===============================
// the gambler 500 is an off road race in Oregon where you can 
// only spend $500 to purchase your racing vehicle.
// https://www.gambler500.com/post/what-makes-a-gambler-car
// default constructor
gambler_500::gambler_500(void)
{
    AWD = nullptr;
    price = 0.00;
    lbs_weight = 0;
    year = 0000;
}

// param constructor
gambler_500::gambler_500(const char *MAKE, const string &MODEL, 
		const int &EXPERIENCE, const double &PRICE, 
		const double &TOTAL_LBS, const int &YEAR, 
		const char *DRIVETRAIN)
		: vehicle(MAKE, MODEL, EXPERIENCE)
{
    // exception handling
    try
    {
        AWD = new char[strlen(DRIVETRAIN) + 1];
        strcpy(AWD, DRIVETRAIN);
    }
    catch (std::bad_alloc& exception)
    {
       cerr << "Bad Alloc Detected: " << exception.what();
    }  

    price = PRICE;
    lbs_weight = TOTAL_LBS;
    year = YEAR;
}

// assignment operator 
gambler_500 gambler_500::operator = (const gambler_500 &src)
{
    // self assignment?
    if (this == &src) return *this;

    // delete memory
    if (AWD) delete [] AWD;

    // exception handling
    try
    {
        AWD = new char[strlen(src.AWD) + 1];
        strcpy(AWD, src.AWD);
    }
    catch (std::bad_alloc& exception)
    {
       cerr << "Bad Alloc Detected: " << exception.what();
    }  

    price = src.price;
    lbs_weight = src.lbs_weight;
    year = src.year;
    return src;
}

// overload the ostream to make sure derived members are handled
ostream & operator << (ostream &output, const gambler_500 &to_display)
{
    // the only way to be able to overload AND use this operator
    // is to add formatting for display
    output << static_cast<const vehicle&>(to_display);
    char *temp; 
    if (to_display.AWD)
    {
        // exception handling
        try
	{
	    temp = new char[strlen(to_display.AWD) + 1];
  	    strcpy(temp, to_display.AWD);
	}
        catch (std::bad_alloc& exception)
        {
            cerr << "Bad Alloc Detected: " << exception.what();
        }  
    }
    output << "Drivetrain: " << temp << endl;
    output << "Year: " << to_display.year << endl;
    output << "Weight (lbs): " << to_display.lbs_weight << endl;
    output << "Price: $" << to_display.price << endl;
    return output;
}

// destructor
gambler_500::~gambler_500(void)
{
    // This was causing a double free for some reason
    //if (AWD) delete [] AWD;
    //AWD = nullptr;
    price = 0.00;
    lbs_weight = 0;
    year = 0000;
}

// the car will interact with an array of events
int gambler_500::simulate_race(forward_list <event> &race)
{
    int difficulty {0};

    // loop through each event in the array and calculate
    for (auto &event : race)
    {
        // set random obstacle data to for difficulty
        total_time += event.obstacle();
	difficulty = event.get_intensity();
	if (lbs_weight >= 3000) total_time += 30;	
	if (year < 2000) difficulty += 5;
    }
    return total_time;
}

/*
// calculate damage
// calculate remaining fuel
int gambler_500::calculate(void)
{

    return 0;
}

// if excessive damage
// if low/no fuel
bool gambler_500::break_down(void)
{
    return false;
}

// add extra 3 min to time
bool gambler_500::repair(void)
{
    return false;
}
*/

// ========================== ELECTRIC CAR ==========================
// default constructor
electric_car::electric_car(void)
{
    charge_frequency = 0;
    energy_tank = 100;
    save_mode = false;
}

// param constructor
electric_car::electric_car(const char *MAKE, const string &MODEL,
	 	const int &EXPERIENCE, const int &CHARGE_FREQ) 
		: vehicle(MAKE, MODEL, EXPERIENCE)
{ 
    charge_frequency = CHARGE_FREQ;
    energy_tank = 100;
    save_mode = false;
}

// overload the ostream to make sure derived members are handled
ostream & operator << (ostream &output, const electric_car &to_display)
{
    //make = new char[strlen(src.make) + 1];
    //strcpy(make, src.make);
    // the only way to be able to overload AND use this operator
    // is to add formatting for display
    output << static_cast<const vehicle&>(to_display);
    output << "Charge Frequency Level: " << to_display.charge_frequency << endl;
    output << "Energy Tank: " << to_display.energy_tank << endl;

    return output;
}

// destructor
electric_car::~electric_car(void)
{
    charge_frequency = 0;
    energy_tank = 0;
    save_mode = false;
}

// the car will interact with an array of events
int electric_car::simulate_race(forward_list <event> &race)
{
    int difficulty {0};

    // loop through each event in the array and calculate
    for (auto &event : race)
    {
        // evaluate energy tank at every obstacle
	if (energy_tank < 50)
	{
	    // save mode kicks on and slows the vehicle down
	    save_mode = true;
	    total_time += 30;
	}
        // set random obstacle data to for difficulty
        total_time += event.obstacle();
	cout << "TIME: " << total_time << endl;
	energy_tank -= event.get_intensity();

	// recharge the vehicle
        if (event.get_interaction() == "Power Strip")
	{
	    energy_tank += 3 * difficulty;
	    cout << "get interaction is working." << endl;
	}
    }
    return total_time;
}


/*
// if energy tank gets low, switch mode
bool electric_car::energy_saving_mode(void)
{
    save_mode = true;
    return save_mode;
}

// jump over opponents
bool electric_car::hover_jump(void)
{
    if (!save_mode)
    {
        energy_tank -= 7;
        return true;
    }
    return false;
}

// short burst of total_time
bool electric_car::jet_boost(void)
{
    if (energy_tank > 5)
    {
        //total_time += 50;
        energy_tank -= 5;
	return true;
    }
    return false;
}

// find recharge station
bool electric_car::recharge(void)
{
    energy_tank = 100;
    save_mode = false;
    return true;
}
*/


// ============================ MARIO KART ============================
// default constructor
mario_kart::mario_kart(void)
{
    power_tank = 0;
    coins = 0;
    banana_peel = 0;
    rainbow_bomb = 0;
    shell = 0;
}

// param constructor
mario_kart::mario_kart(const char *MAKE, const string &MODEL,
       		const int &EXPERIENCE)
		: vehicle(MAKE, MODEL, EXPERIENCE)
{
    power_tank = 0;
}

// destructor
mario_kart::~mario_kart(void)
{
    power_tank = 0;
    coins = 0;
    banana_peel = 0;
    rainbow_bomb = 0;
    shell = 0;
}

// the car will interact with an array of events
int mario_kart::simulate_race(forward_list <event> &race)
{
    int difficulty {0};

    // loop through each event in the array and calculate
    for (auto &event : race)
    {
        // evaluate energy tank at every obstacle
	if (power_tank < 50)
	{
	    // save mode kicks on and slows the vehicle down
	    total_time += 30;
	}
        // set random obstacle data to for difficulty
        total_time += event.obstacle();
	power_tank -= event.get_intensity();
        if (event.get_interaction() == "Collision")
	{
	    cout << "You slipped on a banana!" << endl;
	    total_time += 30 + (rand() %90);
	}

	// power strip!
        if (event.get_interaction() == "Power Strip")
	{
	    power_tank += 3 * difficulty;
	}
    }
    return total_time;
    
}

// pass power strip
// happens every time we finish a lap
int mario_kart::power_up(void)
{
    return 0;
}

// purchase obstacles
bool mario_kart::purchase(void)
{
    return false;
}

// banana peel, rainbow bomb, shell
int mario_kart::throw_obstacle(void)
{
    return 0;
}

// get hit by obstacle or run into wall
bool mario_kart::collision(void)
{
    return false;
}

/*______________________________________________________________________ 
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------ */
