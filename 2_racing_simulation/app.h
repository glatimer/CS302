#include <iostream>
#include <algorithm>
#include <forward_list>
#include <cstring>
#include <vector>
#include "vehicle.h"
#include "DLL.h"
#include "vehicle.h"
//#include "event.h"
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
	 In an attempt to abstract some of the code from main, 
    I will define functions here that will be needed for the client 
	 experience to come together to be called from main().
----------------------------------------------------------------------- */

using std::string;
using std::vector;
static int SIZE = 25;

class app
{
    public:
    app(void);
    ~app(void);

    void greeting(void);
    void finale(const int option);
    int choose_race(const int &choice);
    int build_race(void);

    template <typename TYPE>
    int build_roster(DLL <TYPE> &roster);

    template <typename TYPE>
    int display_roster(const DLL<TYPE> &roster);
    
    template <typename TYPE>
    int add_contestant(DLL <TYPE> &roster);

    template <typename TYPE>
    int start_race(TYPE &d1, TYPE &d2, TYPE &d3);

    private:
    forward_list <event> race_course;
    int option;
};


