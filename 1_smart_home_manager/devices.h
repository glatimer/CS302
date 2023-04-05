#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>


/* ===============================================================================
                       CS302 Assignment 1 - Genevieve Latimer
   -------------------------------------------------------------------------------
	   devices.h is were we will be defining our classes and prototypes
          for our heirarchy.  We will have a device base class as well as its 
            derived classes: smart_thermostat, smart_lock, and smart_sound. 
   =============================================================================== */
using std::string;
using std::vector;

const int SIZE = 40;


// ......................... HIERARCHY device base class .........................
class device
{
	public:
	device(void);
	device(const char *a_name, const bool &is_wifi);
	~device();
	device(const device &to_copy);
	device& operator = (const device &input);
	int calculate_date_time();
	bool compare_name(const char *to_compare);
	bool wifi_status(void);
	int calculate_standard_time(int &hour);
	string &convert_DOW(const int num_DOW);
        string &convert_month(const int num_month);
	int display(void);
	int clear_members(void);

	private:
	char * name;	// char* element 1
	bool wifi;
	int DOW, month, date, year;
	string MONTH, dow;
	int hour, min;
	string am_pm;
};
   

//......................... HIERARCHY derived thermostat class .........................
class thermostat: public device
{
	public:
	thermostat();
	thermostat(const char *a_name, const bool is_wifi, 
	           const int &a_temp, const char *a_mode); 
	thermostat(const thermostat & to_copy);
	thermostat& operator = (const thermostat & input);
	~thermostat();
	int set_temperature(const int &new_temperature);
	int add_sensor(const string &location);
	int display(void);
	int clear_members(void);

	private:
	int curr_temperature;
	char * mode; 		// char* element 2
	vector <string> zones;
};


// ......................... HIERARCHY smart_lock derived class .........................
class smart_lock: public device
{
	public:
	smart_lock(void);
	smart_lock(const char *a_name, const bool &is_wifi, const int &new_PIN);
	~smart_lock(void);
	smart_lock& operator=(const smart_lock &input);
	bool check_lock(void);
	bool unlock(const int &input_PIN);
	bool lock(const int &input_PIN);
	bool PIN_compare(const int &input_PIN);
	bool compare_masterPIN(const int &input_PIN);
	bool add_PIN(const int &master, const int to_add);
	int add_sensor(const string &location);
	int display(void);
	int clear_members(void);

	private:
	bool secure;
	vector <string> network;
	vector <int> PINs;
};



