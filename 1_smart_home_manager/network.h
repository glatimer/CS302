#include <string>
#include "devices.h"
/* ===============================================================================
                       CS302 Assignment 1 - Genevieve Latimer
   -------------------------------------------------------------------------------
   	CLL.h contains the infrastructure needed for creating a network
			     of smart_sound devices.  

          The SMART_SOUND class "is a" device plus more and the object 
       		  	  represents a speaker element.  

   The NODE class is derived from smart_sound, so it "is a" smart_sound device 
   	  and will manage our memory pointers within the data structure.  

      The CLL class is a circularly linked list data structure that represents
   a network of smart_sound devices. The network will be organized by zone and the 
	application will be able to choose a zone to turn on/off, and adjust
		 the volume of the smart_sound devices in that zone. 
   =============================================================================== */
using std::string;

// derived class
class smart_sound: public device
{
	public:
	smart_sound();
	smart_sound(const bool &is_wifi, const char* new_name, 
	       	    const string &new_zone);
	~smart_sound();
	bool turn_on(void);
	bool turn_off(void);
	bool compare_zone(const string &zone_tocompare);
	int change_volume(const int &new_volume);
	int display(void);
	int clear_members(void);

	private:
	bool power_button;
	string zone;
	int volume_level;
};

// node derived from smart_sound to be used in CLL
class node : public smart_sound
{
	public:
	node();
	node(const smart_sound &new_sound);
	node(const node &to_copy);
	node& operator=(const node &input);
	~node();
	void set_next(node *new_next);
	node *& get_next(void);
	bool has_next(void) const;

	private: 
	node *next;
};


// circularly linked list to hold a network of smart_sound devices
class CLL 
{
	public: 
	CLL();
	CLL(const CLL &to_copy);
	CLL&operator=(const CLL &source);
	~CLL();

	// wrapper functions

	int insert(const smart_sound &new_sound);

	int power(const string &zone_tofind, const int &off_on, const int &vol);
        int display_one(const char *to_display);
	int display_all(void) const;
	int remove(const char *remove_name);
	int remove_all(void);

	private:
	node *rear;
	node *retrieval;

	// recursive functions
	void copy(node *dest_rear, const node *source_rear, const node *stop);
	int insert(node *head, const smart_sound &new_sound);
	node*& retrieve(const char *a_name);
	node*& retrieve(node *rear, const char *a_name);
	int power(node *head, const string &zone_tofind, const int &off_on, const int &vol);
        int display_one(node *is_found);
	int display_all(node *rear) const;
	int remove(node *&rear, const char *remove_name);
	int remove_all(node *& curr);
};

