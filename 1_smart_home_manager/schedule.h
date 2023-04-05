#include <iostream>
#include <string>
/* ===============================================================================
                       CS302 Assignment 1 - Genevieve Latimer
   -------------------------------------------------------------------------------
     One function of the application will be to allow smart_thermostat to fill 
          a schedule of temperature presets. The schedule class will hold
               a title, day of the week, start time, and end time.

      The application will allow smart_lock and smart_thermosat to create a 
         network of sensors that will inform the decisions of the devices. 

      The application will allow smart_sound to develop a network of audio 
              objects that will be remotely controlled by the user.
   =============================================================================== */
using std::string;

const int SIZE = 7;

// smart_thermostat will implement the use of an ARR_LLL containing 
// a collection of schedules
class schedule
{
   	public:
	schedule();
	schedule(const string &a_title, const int a_DOW, 
    		const string &to_start, const string &to_finish);
	~schedule();
	int display(void);
	int clear_members(void);

	private:
	string title;
	string DOW;
	string start_time;
	string finish_time;
};


// the smart_thermostat device will have an array of linked lists
// containing schedule objects to simulate a preset feature
class NODE : public schedule
{
   	public:
	NODE();
	~NODE(void);
	NODE(const schedule & new_schedule);
	NODE(const NODE & to_copy);
	NODE& operator=(const NODE & input);
	void set_next(NODE * new_next);
	NODE *& get_next();

	private:
	NODE * next;
};


//ARR_LLL
class ARR_LLL
{
	public:
	ARR_LLL(int size=SIZE);
	~ARR_LLL(void);

	// wrapper functions
	int insert(const NODE &to_add);
	int display(const string &a_DOW);
	int display_all(void) const;
	int remove(const string &to_remove);
	int remove_all(void) const;

	private:
	NODE **head_arr; // dynamically allocated array of pointers
	int arr_size; // size of the array
	string DAY;
	
	// recursive functions
//	int insert(NODE *head_arr, const NODE &to_add);
//	NODE*& retrieve(const NODE &to_find);
//	NODE*& retrieve(const NODE &to_find);
//	int display(const string &a_DOW);
//	int display_all(void) const;
//	int remove(const string &to_remove);
//	int remove_all(void) const;
};
