#include <memory>
#include <list>
#include <exception>
#include "health_event.h"

/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
       BST.h will contain the node class and BST data structure class
   ........................................................................
   ------------------------------------------------------------------------ */
using std::string;
using std::unique_ptr;

class node
{
	public:
	node(void);
	node(health_event* to_add);
	node(const node& to_copy);
	node& operator = (const health_event& source);
	~node(void);
	unique_ptr<node>& get_left(void);
	unique_ptr<node>& set_left(unique_ptr<node> new_left);
	unique_ptr<node>& get_right(void);
	health_event* get_health_event(void);
	void set_health_event(health_event* new_data);
	bool greater_than(health_event* new_data);
	bool less_than_or_equal(health_event* new_data);
	bool compare_events(health_event* to_compare);
	bool compare_name(const string& to_find);
	void set_list(health_event* to_add);
	void display(void) const;

	protected:
	unique_ptr<node> left;
	unique_ptr<node> right;
	health_event* event;
	std::list<health_event*> duplicates;
};

class BST
{
	public: 
	BST(void);	
	BST(const BST& to_copy);		
	BST& operator=(const BST& source);
	~BST(void);			
	void insert(health_event* to_add);
	int display(void) const;	
	health_event* search_name(string& to_find);
	int edit_data(const string& to_edit);
	int complete_task(const string &to_complete);
	void remove(string& to_find);	
	int remove_all(void);		

	protected:
	unique_ptr<node> root;
	void insert(unique_ptr<node>& root, health_event* to_add);
	int display(const unique_ptr<node>& root) const;
	health_event* search_name(unique_ptr<node>& root, string& to_find);
	int edit_data(unique_ptr<node>& root, const string& to_edit);
	int complete_task(unique_ptr<node>& root, const string &to_complete);
	//void remove(unique_ptr<node>& root, health_event*& to_remove);
	void remove(unique_ptr<node>& root, string &to_find);
	int remove_all(unique_ptr<node>& root);			
};
