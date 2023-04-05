#include "devices.h"

/* ===============================================================================
                       CS302 Assignment 1 - Genevieve Latimer
   -------------------------------------------------------------------------------
   			       base class = device
		            derived class = thermostat
   			    derived class = smart_lock
			    derived class = smart_sound (found in network.h)
   =============================================================================== */

using namespace std;   

// ............................... base class device ...............................
// defualt constructor
device::device()
{
    name = nullptr;
    wifi = false;

    // current date/time based on current system
    calculate_date_time();
}

// param constructor
device::device(const char *a_name, const bool &is_wifi)
{
    name = new char[strlen(a_name) + 1];
    strcpy(name, a_name);
    wifi = is_wifi;
    calculate_date_time();
}

// destructor
device::~device()
{
    clear_members();
}

// copy constructor
device::device(const device & to_copy)
{
    // if the passed in object isn't empty, copy it
    if (to_copy.name)
    {
        name = new char[strlen(to_copy.name) + 1];
        strcpy(name, to_copy.name);
        wifi = to_copy.wifi;
        DOW = to_copy.DOW;
        month = to_copy.month;
        date = to_copy.date;
        year = to_copy.year;
        hour = to_copy.hour;
        min = to_copy.min;
        am_pm = to_copy.am_pm;
    }
}

// assignment operator
device& device::operator=(const device & input)
{
    // are we trying to assign to the same address?
    // check for self assignment
    if (this == &input)  
    {
        return *this;
    }
    // if char * is not empty
    // deallocate any dynamic memory
    if (name) 
    {
	delete [] name;
    }
    name = new char [strlen(input.name) + 1];
    strcpy(name, input.name);
    wifi = input.wifi;
    // do I just keep copying the same address?
    // do I even need to update? I think so.
    DOW = input.DOW;
    month = input.month;
    date = input.date;
    year = input.year;
    hour = input.hour;
    min = input.min;
    am_pm = input.am_pm;
    return *this;
}

// calculate time and date
// resource: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
int device::calculate_date_time()
{
    // current date/time based on current system
    time_t now = std::time(0);
    tm *ltm = localtime(&now);
    DOW = 1 + ltm->tm_wday;
    month = 1 + ltm->tm_mon; 
    date = ltm->tm_mday;
    year = 1900 + ltm->tm_year;
 
    hour = ltm->tm_hour;
    min = ltm->tm_min;
    am_pm = "am";
    return 0;
}

// return true if names match
// strcmp() returns 0 if contents match
bool device::compare_name(const char *to_compare)
{
    int result = strcmp(to_compare, name);
    if (result == 0) return true;
    else return false;
}

// is the device connected to the wifi? 
bool device::wifi_status(void)
{
    return wifi;
}

// convert military time into standard time
int device::calculate_standard_time(int &hour)
{
    if (hour > 12) 
    {
        hour -= 12;
	am_pm = "pm";
    }
    return hour;
}

// convert number day of the week into string day of the week
string &device::convert_DOW(const int num_DOW)
{
    switch (num_DOW)
    {
       case 1:
           dow = "Sunday";
	   break;
       case 2:
           dow = "Monday";
	   break;
       case 3:
           dow = "Tuesday";
	   break;
       case 4:
           dow = "Wednesday";
	   break;
       case 5:
           dow = "Thursday";
	   break;
       case 6:
           dow = "Friday";
	   break;
       case 7:
           dow = "Saturday";
	   break;
       default: 
           dow = "invalid";
	   break;
       }
       return dow;
}

// convert number month into string month
string &device::convert_month(const int num_month)
{
    switch (num_month)
    {
       case 1:
           MONTH = "January";
	   break;
       case 2:
           MONTH = "February";
	   break;
       case 3:
           MONTH = "March";
	   break;
       case 4:
           MONTH = "April";
	   break;
       case 5:
           MONTH = "May";
	   break;
       case 6:
           MONTH = "June";
	   break;
       case 7:
           MONTH = "July";
	   break;
       case 8:
           MONTH = "August";
	   break;
       case 9:
           MONTH = "September";
	   break;
       case 10:
           MONTH = "October";
	   break;
       case 11:
           MONTH = "November";
	   break;
       case 12:
           MONTH = "December";
	   break;
       default:
           MONTH = "Invalid";
	   break;
    }
    return MONTH;
}

// display name, wifi status, date, and time
int device::display(void)
{
    // convert date and time 
    string Month {' '};
    Month = convert_month(month); 

    string Day {' '};
    Day = convert_DOW(DOW); 

    calculate_standard_time(hour);

    // display
    cout << "Name: " << name << endl;
    cout << boolalpha  << "WIFI status: " <<  wifi << endl;
    cout << "Date: " << Day << ", " << Month << " " 
         << date << ", " << year << endl;
    cout << "Time: " << hour << ":" << min << am_pm << endl; 
    return 0;
}

// clear data
int device::clear_members(void)
{
    // free dynamic memory
    if (name) delete [] name;

    // reset members
    name = nullptr;
    wifi = false;
    DOW = 0;
    month = 0; 
    date = 0; 
    year = 0; 
    hour = 0; 
    min = 0; 
    am_pm = "";
    return 1;
}

// ............................... derived class thermostat ...............................
thermostat::thermostat()
{
    curr_temperature = 0;
    mode = nullptr;
}

// param constructor
thermostat::thermostat(const char *a_name, const bool is_wifi, 
		       const int &a_temp, const char* a_mode) 
                       : device(a_name, is_wifi)
{
    curr_temperature = a_temp;
    mode = new char[strlen(a_mode) + 1];
    strcpy(mode, a_mode);
}

// destructor
thermostat::~thermostat()
{
    clear_members();
}

// copy constructor
thermostat::thermostat(const thermostat & to_copy)
                      :device(to_copy) 
{
    // if the passed in object isn't empty, copy it
    if (to_copy.mode)
    {
    	curr_temperature = 0;
        mode = new char[strlen(to_copy.mode) + 1];
	strcpy(mode, to_copy.mode);

	// copy vector
	if (!to_copy.zones.empty()) 
	{
	    for (auto obj : to_copy.zones)
	    {
	        zones.push_back(obj);
   	    }
	}
    }
}


// assignment operator
thermostat& thermostat::operator = (const thermostat & input)
{
    // are we trying to assign to the same address?
    // check for self assignment
    if (this == &input)  
    {
        return *this;
    }

    // trigger parent's assignment operator
    device::operator=(input);

    // if char * is not empty
    // deallocate any dynamic memory
    if (mode) 
    {
	delete [] mode;
    }
    curr_temperature = input.curr_temperature;
    mode = new char [strlen(input.mode) + 1];
    strcpy(mode, input.mode);

    // if there is content in the input vector
    if (!input.zones.empty())
    {
        for (auto obj : input.zones)
        {
    	    zones.push_back(obj);
        }
    }
        
    return *this;
}


// change the temperature of the thermostat
int thermostat::set_temperature(const int &new_temperature)
{
    curr_temperature = new_temperature;
    return curr_temperature;
}

// add a temperature sensing device to the network
int thermostat::add_sensor(const string &location)
{
    zones.push_back(location); 
    return 1;
}

// display the date, time, temperature
int thermostat::display(void)
{
    cout << ".............................................." << endl;
    device::display();
    cout << "Mode: " << mode << endl;
    cout << "Current Temperature: " << curr_temperature << endl;
    if (!zones.empty()) 
    {
    	for (auto element : zones)
	{
	    cout << "Sensor: " << element << endl;
	}
    }
    return 1;
}

// clear data
int thermostat::clear_members(void)
{
    // free dynamic memory
    if (mode) delete [] mode;

    // reset members
    curr_temperature = 0;
    mode = nullptr;

    // clear data from vector
    if (!zones.empty())
    { 
	for (auto element : zones)
	{
	    element.erase();
	}
    }
    return 1;
}


// ............................... derived class smart_lock ...............................
// default constructor
// need to add a pin object to the vector rather than just a vector of ints 
// so that we can store an associated name with the PIN
smart_lock::smart_lock(void)
{
    secure = false;
}

// probably need a param constructor
smart_lock::smart_lock(const char *a_name, const bool &is_wifi, const int &new_PIN)
                       : device(a_name, is_wifi)
{
    secure = false;
    PINs.push_back(new_PIN);
}

// destructor
smart_lock::~smart_lock(void)
{
    clear_members();
    if (!PINs.empty())
    {
        PINs.clear();
    }
}

// assignment operator
smart_lock& smart_lock::operator=(const smart_lock &input)
{
    // are we trying to assign to the same address?
    // check for self assignment
    if (this == &input)  
    {
        return *this;
    }

    // trigger parent's assignment operator
    device::operator=(input);

    secure = input.secure;

    // if there is content in the input vector
    if (!input.PINs.empty())
    {
        for (auto obj : input.PINs)
        {
    	    PINs.push_back(obj);
        }
    }
        
    return *this;
}

// remotely check to see if the door is locked
bool smart_lock::check_lock(void)
{
    return secure;
}

// unlock the door with a PIN
bool smart_lock::unlock(const int &input_PIN)
{
    bool success {false};
    if (PIN_compare(input_PIN) == true)	
    {
        secure = false;
        success = true;
    }
    return success;
}

// lock the door with a PIN
bool smart_lock::lock(const int &input_PIN)
{
    bool success {false};
    if (PIN_compare(input_PIN) == true)
    {
        secure = true;
        success = true;
    }
    return success;
}



// unlock the door using a PIN. If the PIN is valid
// the door unlocks.  Might add a log component to this:
// write to external file the time and date and PIN used
bool smart_lock::PIN_compare(const int &input_PIN)
{
    bool match {false};
    // search the vector of PINs to see if we find a match
    for (auto obj : PINs)
    {
        // if we find a match, the door will unlock
    	if (input_PIN == obj) 
	{
	    match = true;
	}
    }
    return match;
}

// only the master PIN created at setup will have 
// authority over network of smart_locks
bool smart_lock::compare_masterPIN(const int &input_PIN)
{
    bool result {false};
    if (PINs[0] == input_PIN)
    {
        result = true;
    }
    return result;
}

// Add a pin to the list
bool smart_lock::add_PIN(const int &master, const int to_add)
{
    bool success {false};
    if (PINs[0] == master)
    {
        PINs.push_back(to_add);
	success = true;
    }

    return success;
}


// we can make an array of strings to keep track of
int smart_lock::add_sensor(const string & new_string)
{
    network.push_back(new_string);
    return 0;
}

// display the name, date, time, and if the door is locked
int smart_lock::display(void) 
{
    int num = PINs.size();
    int i = 1;

    device::display();
    cout << "Locked: " << boolalpha << secure << endl;
    // we are not going to display the PINs. This would be a safety concern.
    cout << "Number of PINs Stored: " << num << endl;
    cout << "____________ Sensor Network ____________" << endl;
    for (auto item : network)
    {
        cout << "[" << i << "] ";
	cout << item << endl;
	++i;
    }
    int j = 1;
    cout << "____________ PINs ____________" << endl;
    for (auto item : PINs)
    {
        cout << "[" << j << "] ";
	cout << item << endl;
	++j;
    }


    return 1;
}

int smart_lock::clear_members(void)
{
    // reset members
    secure = false;

    // clear data from vector
    if (!network.empty())
    {
        network.clear();
    }

    // check this loop and fix bug
    if (!PINs.empty())
    {
        PINs.clear();
    }
    return 0;
}



