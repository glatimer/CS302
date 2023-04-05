#ifndef EVENT_H
# define EVENT_H
#include <iostream>
#include <cstring>
#include <forward_list>
#include "event.h"

/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
   vehicle.h is where the heirarchy of class objects will be defined.
			    Base = vehicle
			 derived = gambler_500
			 derived = electric_car
			 derived = mario_kart
----------------------------------------------------------------------- */

using std::string;
using std::forward_list;
using std::ostream;
using std::istream;


// ========================== base class ==========================
class vehicle
{
    public: 
    vehicle(void);
    vehicle(const char *MAKE, const string &MODEL,
    	    const int &EXPERIENCE); 
    ~vehicle(void);
    vehicle(const vehicle &to_copy);

    // assignment - vehicle1 = vehicle2
    vehicle operator = (const vehicle &src);

    // relational - evaluate total_time
    bool operator <  (const vehicle &to_compare);
    bool operator <= (const vehicle &to_compare);
    bool operator >  (const vehicle &to_compare);
    bool operator >= (const vehicle &to_compare);

    // equality - compare make and model 
    bool operator == (const vehicle &to_compare) const;  
    bool operator != (const vehicle &to_compare) const;  

    // I/O - cin new vehicle contents, cout vehicle display
    friend istream & operator >> (istream &in, vehicle &input);
    friend ostream & operator << (ostream &out, const vehicle &output);

    // arithmetic - add a vehicle to the race
    vehicle  operator +  (const vehicle &to_add);
    vehicle& operator += (const vehicle &to_add);

    protected:
    char* make;
    string model;
    int total_time;
    int driver_experience; // in years
};

// ========================== derived class ==========================
// the gambler 500 is an off road race in Oregon where you can 
// only spend $500 to purchase your racing vehicle.
// https://www.gambler500.com/post/what-makes-a-gambler-car
class gambler_500 : public vehicle
{
    public:
    gambler_500(void);
    gambler_500(const char *MAKE, const string &MODEL, 
    		const int &EXPERIENCE, const double &PRICE, 
		const double &TOTAL_LBS, const int &YEAR, 
		const char *drivetrain);
    gambler_500 operator = (const gambler_500 &src);
    friend ostream & operator << (ostream &output, const gambler_500 &to_display);
    ~gambler_500(void);

    // race interaction
    int simulate_race(forward_list<event> &race);

    protected:
    char *AWD;
    double price;
    double lbs_weight;
    int year;
};

// ========================== derived class ==========================
class electric_car : public vehicle
{
    public:
    electric_car(void);
    electric_car(const char *MAKE, const string &MODEL,
    		 const int &EXPERIENCE, const int &CHARGE_FREQ);
    friend ostream & operator << (ostream &output, const electric_car &to_display);
    ~electric_car(void);

    // race interaction
    int simulate_race(forward_list<event> &race);
    bool energy_saving_mode(void);  // if energy tank gets low, switch 
    bool hover_jump(void);  // jump over opponents?
    bool jet_boost(void);  // short burst of total_time
    bool recharge(void);  // find recharge station

    protected:
    int charge_frequency; // from level 1-10 [worst to best]
    int energy_tank;
    bool save_mode;
};

// ========================== derived class ==========================
class mario_kart: public vehicle
{
    public:
    mario_kart(void);
    mario_kart(const char *MAKE, const string &MODEL,
    	       const int &EXPERIENCE); 
//      	       const int &POWER);
    ~mario_kart(void);

    // race interaction
    int simulate_race(forward_list<event> &race);
    int power_up(void);  // pass power strip
    bool purchase(void);  // purchase obstacles
    int throw_obstacle(void); // banana peel, rainbow bomb, shell
    bool collision(void);  // get hit by obstacle or run into wall

    protected:
    int power_tank;
    int coins;
    int banana_peel;
    int rainbow_bomb;
    int shell;
};
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------ */
#endif //EVENT_H
