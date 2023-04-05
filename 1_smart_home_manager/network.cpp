#include "network.h"
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
using namespace std;

// ............................... derived class smart_sound ...............................
// default constructor
smart_sound::smart_sound()
{
    clear_members();
}

// param constructor
smart_sound::smart_sound(const bool &is_wifi, const char* new_name, const string &new_zone)
  			 : device(new_name, is_wifi) 
{
    // bool dupe {false};

    power_button = false;
    volume_level = 0;
    zone = new_zone;
}

// destructor
smart_sound::~smart_sound()
{
    clear_members();
}

// turn the speaker on
bool smart_sound::turn_on(void)
{
    power_button = true;
    return power_button;

}

// turn the speaker off
bool smart_sound::turn_off(void)
{
    power_button = false;
    return power_button;
}

// search the network by zone 
bool smart_sound::compare_zone(const string &zone_tocompare)
{
    bool match {false};
    if (zone == zone_tocompare)
    {
       match = true;
    }
    return match;
}

// change volume by zone
int smart_sound::change_volume(const int &new_volume)
{
    volume_level = new_volume;
    return volume_level;
}

// display name, zone, time, date
int smart_sound::display(void)
{
    device::display();
    if (power_button == true)
    {
        cout << "Power: On" << endl;
    }
    else
    {
        cout << "Power: Off" << endl;
    }

    cout << "Zone: " << zone << endl;
    cout << "Volume Level: " << volume_level << endl;
    return 0;
}

// clear data
int smart_sound::clear_members(void)
{
    power_button = false;
    zone = " ";
    volume_level = 0;
    return 0;
}

// ......................................... derived node class .........................................
// node derived from smart_sound to be used in CLL
// default constructor
node::node()
{
    next = nullptr;
}

// param constructor
node::node(const smart_sound &new_sound)
          : smart_sound(new_sound)
{
    next = nullptr;
}

// copy constructor
node::node(const node &to_copy) : smart_sound(to_copy)
{
    next = to_copy.next;
}

// assignment operator
node& node::operator=(const node &input)
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
    if (next) 
    {
	delete [] next;
	next = nullptr;
    }

    if (input.next)
    {
        next = input.next;
    }
    else
    {
        next = nullptr;
    }
    return *this;
}

// destructor
node::~node()
{
    next = nullptr;
}

// set next pointer
void node::set_next(node *new_next)
{
    next = new_next;
}


// return next pointer
node *& node::get_next(void)
{
    return next;
}

// check if next is null
bool node::has_next(void) const
{
    if (next) return true;
    else return false;
}


// ................................. Circular Linked List .................................
// circularly linked list to hold a network of smart_sound devices
// default constructor
CLL::CLL()
{
    rear = nullptr;    
}


// copy constructor acts as a wrapper
CLL::CLL(const CLL &to_copy)
{
    if (!to_copy.rear) return;
    copy(rear, to_copy.rear->get_next(), to_copy.rear);
}

// recursive copy 
void CLL::copy(node *dest_rear, const node *source_rear, const node *stop)
{
    node *temp = new node(*source_rear);

    // if the CLL is empty
    if (!dest_rear)
    {
        // point to itself
        temp->set_next(temp);
	dest_rear = temp;
    }
    else
    {
        temp->set_next(dest_rear->get_next());
	dest_rear->get_next() = temp;
	dest_rear = temp;
    }
    if (source_rear == stop) return;
    copy(dest_rear->get_next(), source_rear, stop);
}


// destructor acts as a wrapper function
CLL::~CLL()
{
    if (!rear) return;
    remove_all(rear->get_next());
}

// wrapper for client remove all
int CLL::remove_all(void)
{
    if (!rear) return 0;
    return remove_all(rear->get_next());
}

// recursive remove all elements from CLL
int CLL::remove_all(node *& head)
{
    int count {0};
    if (rear)
    {
	rear->set_next(nullptr);
	while (head)
	{
	    rear = head->get_next();
	    delete head;
	    head = rear;
	    ++count;
	}
        head = nullptr;
	rear = nullptr;
    }
    return count;
}


// assignment operator
CLL& CLL::operator=(const CLL &source)
{
    if (this == &source) return *this;
    remove_all(rear);
    copy(rear, source.rear->get_next(), source.rear);
    return *this;
}

// take an object in as an argument and insert into the list at rear
int CLL::insert(const smart_sound &new_sound)
{
    // if first element insert 
    if (!rear) 
    {
        rear = new node(new_sound);
	rear->set_next(rear);
	return 1;
    }
    // otherwise
    return insert(rear->get_next(), new_sound);
}

// add an object to the list at rear
int CLL::insert(node *head, const smart_sound &new_sound)
{
    if (head == this->rear)
    {
        node *temp = new node(new_sound);
	temp->set_next(rear->get_next());
	rear->set_next(temp);
	rear = temp;
	return 1;
    }
    insert(head->get_next(), new_sound);
    return 0;
}

// remove one object by name
int CLL::remove(const char *remove_name)
{
    if (!rear) return 0;
    return remove(rear->get_next(), remove_name);
}


// remove one object by name
int CLL::remove(node *&head, const char *remove_name)
{
    if (head == this->rear)
    {
        if (head->compare_name(remove_name) == true)
	{
	    delete rear;
	    rear = nullptr;
	    return 1;
	}
    }
    if (head->get_next()->compare_name(remove_name) == true)
    {
        node *hold = head->get_next();
	head->set_next(hold->get_next());
	delete hold;
	hold = nullptr;
	return 1;
    }
    retrieve(head->get_next(), remove_name);
    return 0;
}

// search and retrieve by zone
node*& CLL::retrieve(const char *a_name)
{
    if (!rear) return rear;
    return retrieve(rear->get_next(), a_name);
}

// search and retrieve by zone
node*& CLL::retrieve(node *head, const char *a_name)
{
    if (head == this->rear)
    {
        if (head->compare_name(a_name) == true)
	{
            retrieval = head;
	    return retrieval;
	}
    }
    if (head->compare_name(a_name) == true)
    {
        retrieval = head;
	return retrieval;
    }
    return retrieve(head->get_next(), a_name);
}

// power on or off by zone
int CLL::power(const string &zone_tofind, const int &off_on, const int &volume)
{
    if (!rear) return 0;
    return power(rear->get_next(), zone_tofind, off_on, volume);
}

// power on or off by zone
int CLL::power(node *head, const string &zone_tofind, const int &off_on, const int &volume)
{
    int count {0};
    
    if (head == this->rear)
    {
	    if (head->compare_zone(zone_tofind) == true)
	    {
	       if (off_on == 0)
	       {
		   head->turn_off();
		   head->change_volume(volume);
	       }
	       else if (off_on == 1)
	       {
		   head->turn_on();
		   head->change_volume(volume);
	       }
	    }
	    return count;
        
    }
    if (head->compare_zone(zone_tofind) == true)
    {
       if (off_on == 0)
       {
           head->turn_off();
 	   head->change_volume(volume);
       }
       else if (off_on == 1)
       {
           head->turn_on();
	   head->change_volume(volume);
       }
    }
    return count += power(head->get_next(), zone_tofind, off_on, volume) + 1;
}

// display one item in the list by name
int CLL::display_one(const char *a_name)
{

    node *is_found = retrieve(a_name);
    if (!is_found) return 0;
    return display_one(is_found);
}

// display one item in the list
int CLL::display_one(node *found)
{
    found->display();
    return 1;
}

// display all items in the network
int CLL::display_all(void) const
{
    if (!rear) return 0;
    return display_all(rear->get_next());
}

// display all items in the network
int CLL::display_all(node *head) const
{
    int count {0};
    // traversal starts at rear->next = head
    if (head == this->rear)
    {
        head->display();
	cout << endl;
        return count;
    }
    head->display();
    cout << endl;
    return count += display_all(head->get_next()) + 1;
}

