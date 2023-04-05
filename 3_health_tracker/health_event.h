#include <iostream>
#include <string>
#include <cstring>
/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
       health_event.h will contain the prototypes and class members for
       our health_event hierarchy which will be used to make objects to 
     	 	populate a BST of scheduled health_events.
   ........................................................................
   ------------------------------------------------------------------------ */

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

// used to determine what fitness activity to schedule
enum fit_type
{
    STRENGTH,    // 0 
    CARDIO,      // 1
    GROUP,       // 2
    ADVENTURE    // 3
};

// used to determine what fast/feed window to schedule
enum fast_type
{
    BEGINNER, // 16:8
    MODERATE, // 20:4
    ADVANCED  // 24
};

// Abstract Base Class
class health_event
{
    public:
    health_event(void);
    health_event(const string &TITLE, const string &DATE, 
     		 const string &START);
    virtual ~health_event(void);
    
    // assignment - health_event1 = health_event2
    health_event& operator = (const health_event &source);

    // relational - evaluate total_time
    bool operator <  (const health_event &to_compare);
    bool operator <= (const health_event &to_compare);
    bool operator >  (const health_event &to_compare);
    bool operator >= (const health_event &to_compare);

    // equality - compare make and model 
    bool operator == (const health_event &to_compare) const;  
    bool operator != (const health_event &to_compare) const;  

    // standard functions
    virtual int schedule_event(void);
    virtual int display(void);
    virtual int clear_members(void);
    virtual int edit(void);
    virtual bool complete_task(void) = 0;  // pure virtual
    virtual int celebrate(void); 

    
    string& get_title(void);
    bool compare(const string &tofind);
    health_event& retrieve(const string &title_tofind);

    protected:
    string title;
    string date;
    string start_time; 
    int response;
    bool completed;
};

// Derivative
class fitness : public health_event
{
    public:
    fitness(void);
    fitness(const string &TITLE, const string &DATE, 
     	    const string &START, const fit_type &ACTIVE);
    ~fitness(void);
    
    // assignment - health_event1 = health_event2
    fitness& operator = (const fitness &source);
    
    // standard functions
    int schedule_event(void);
    int display(void);
    int edit(void);

    int set_activity(void);
    bool complete_task(void); 

    protected:
    fit_type activity;
};

// Derivative
class supplements : public health_event
{
    public:
    supplements(void);
    supplements(const string &TITLE, const string &DATE, 
                const string &START, const string &DOSE,
		const bool &WITH_FOOD);
    ~supplements(void);
    
    // assignment - health_event1 = health_event2
    supplements& operator = (const supplements &source);

    // standard functions
    int schedule_event(void);
    int clear_members(void);
    int display(void);
    int edit(void);
    bool complete_task(void);

    protected:
    string dose;
    bool with_food;
};

// Derivative
// Intermittent fasting (IF) 
class IF : public health_event
{
    public:
    IF(void);
    IF(const string &TITLE, const string &DATE, 
       const string &START, const int DURATION);
    ~IF(void);

    // assignment - health_event1 = health_event2
    IF& operator = (const IF &source);
    
    // standard functions
    int schedule_event(void);
    int clear_members(void);
    int display(void);
    bool complete_task(void);

    int edit(void);
//    int countdown(void);   // RTTI option 1: Count down the fasting window 
    int alert(void); 	   // RTTI option 2: It's time to eat!  Let the user know 
    			   // 		     when the fasting window is over.
    protected:
    fast_type window;  
    int duration;     // hours
    bool fast;        
};
