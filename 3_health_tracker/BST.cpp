#include "BST.h"
/* ========================================================================
  	   	 CS302 Assignment #3 - Genevieve Latimer
   ________________________________________________________________________
   ........................................................................
     BST.cpp will implement a binary search tree that contains pointers 
    	   to various derived objects in the abstract base class.
   ........................................................................
   ------------------------------------------------------------------------ */

using namespace std;

// -------------------------------- node --------------------------------
// default constructor
node::node(void): left(new node()), right(new node())
{
    // if the list is not empty, clear it
    for (health_event* event : duplicates)
    {
	event->clear_members();
    }
}

// param constructor
node::node(health_event* to_add) : event(to_add)
{
    left = nullptr;
    right = nullptr;
}

// copy constructor
node::node(const node& to_copy)
{
    event = to_copy.event;
    if (to_copy.left)
    {
        left = make_unique<node>(*to_copy.left);
    }
    if (to_copy.right)
    {
        right = make_unique<node>(*to_copy.right);
    }
    duplicates = to_copy.duplicates;
}

// assignment operator
node& node::operator = (const health_event& source)
{
    return *this;
}

// destructor
node::~node(void)
{
    left.release();
    left = nullptr;
    right.release();
    right = nullptr;
    event->clear_members();
    event = nullptr;
    for (health_event* event : duplicates)
    {
	event->clear_members();
    }
}

// return left pointer
unique_ptr<node>& node::get_left(void)
{
    return left;
}

// set left pointer
unique_ptr<node>& node::set_left(unique_ptr<node> new_left)
{
    //return left = make_unique<node>(*new_left);
    return left = move(new_left);
    //return left;

}

// return right pointer
unique_ptr<node>& node::get_right(void)
{
    return right;
}

// return current event
health_event* node::get_health_event(void)
{
    return event;
}

// set the current object to new_data
void node::set_health_event(health_event* new_data)
{
    event = new_data;
    return;
}

// compare the names to determine where to insert
bool node::greater_than(health_event* new_data)
{
    bool greater {false};
    if (new_data->get_title() > event->get_title()) greater = true;
    return greater;
}

// compare the names to determine where to insert
bool node::less_than_or_equal(health_event* new_data)
{
    bool less_equal {false};
    if (new_data->get_title() <= event->get_title()) less_equal = true;
    return less_equal;
}

// compare objects and return true or false
bool node::compare_events(health_event* to_compare)
{
    bool compare {false};
    if (event == to_compare) compare = true;
    return compare;
}

// compare names and return health_event if found
bool node::compare_name(const string& to_find)
{
    bool match {false};
    if (event->get_title() == to_find) match = true;
    return match;
}

// if a duplicate is found, add the object to the node std::list
void node::set_list(health_event* to_add)
{
    duplicates.push_back(to_add);
    return;
}

// display the contents of this object
void node::display(void) const
{
    int i = 1;
    
    event->display();
    cout << "================ Duplicates ================ " << endl;
    for (auto item : duplicates)
    {
        cout << "[" << i << "] " << endl;
        item->display();
	++i;
    }
    if ( 1 == i)
    {
        cout << "                    NONE                     " << endl;
    }

    cout << "============================================ " << endl;
    return;
}

// -------------------------------- BST --------------------------------
// default constructor
BST::BST(void) : root(nullptr) {}

// copy constructor
BST::BST(const BST &to_copy) {}

// assignment operator
BST& BST::operator = (const BST& source)
{
	return *this;
}

// destructor
BST::~BST(void)
{
    if (!root) return;
    else
    {
	remove_all();
	root = nullptr;
    }
}

// WRAPPER: insert a health_event into the BST
void BST::insert(health_event* to_add)
{
    return insert(root, to_add);
}

// RECURSIVE: insert a health_event into the BST
void BST::insert(unique_ptr<node>& root, health_event* to_add)
{
    if (!root)
    {
//	cout << "Inside BST: " << endl;
	unique_ptr<node> temp(new node(to_add));
	root = move(temp);
	return;
    }
    // add duplicate to node list
    if (root->compare_name(to_add->get_title()) == 1)
    {
	// insert the duplicate into the std::list
	root->set_list(to_add);
	return;
    }

    // otherwise traverse to find the place to insert
    if (root->greater_than(to_add))
    {
	insert(root->get_left(), to_add);
    }  
    else
    {
	insert(root->get_right(), to_add);
    }
}

// WRAPPER: display all
int BST::display(void) const
{
    if (!root) return 0;
    return display(root);
}

// RECURSIVE: display all
int BST::display(const unique_ptr<node>& root) const
{	
    int count {0};
    if (!root) return 0;
    count += display(root->get_right()) + 1;
    root->display();
    cout << endl;
    count += display(root->get_left());
    return count;
}

// WRAPPER: search the tree for a health_event by name
health_event* BST::search_name(string& to_find)
{
    if (!root) return nullptr;
    return search_name(root, to_find);
}

// RECURSIVE: search the tree for a health_event by name
health_event* BST::search_name(unique_ptr<node>& root, string& to_find)
{
    if (!root) return nullptr;
    if (root->compare_name(to_find) == true)
    {
	return root->get_health_event();
    }
    search_name(root->get_left(), to_find);
    search_name(root->get_right(), to_find);
    return root->get_health_event();
}

// WRAPPER: complete a task
int BST::complete_task(const string &to_complete)
{
    if (!root) return 0;
    return complete_task(root, to_complete);
}

// RECURSION: complete a task
int BST::complete_task(unique_ptr<node>& root, const string &to_complete)
{
    int result = 0;
    if (!root) return result;
    if (root->compare_name(to_complete) == true)
    {
        // signal to client that we are completing a fast
	// so that we can upcast the alert() from application.cpp
        if (typeid(*root->get_health_event()) == typeid(IF))
	{
	    result = 2;
	    return result;
	}
	return root->get_health_event()->complete_task();
    }
    result += complete_task(root->get_left(), to_complete);
    result += complete_task(root->get_right(), to_complete);
    return result;
}


// WRAPPER: edit node data
int BST::edit_data(const string& to_edit)
{
    if (!root) return 0;
    return edit_data(root, to_edit);
}


// RECURSIVE: edit node data
int BST::edit_data(unique_ptr<node>& root, const string& to_edit)
{
    if (!root) return 0;
    if (root->compare_name(to_edit) == true)
    {
	return root->get_health_event()->edit();
    }
    edit_data(root->get_left(), to_edit);
    edit_data(root->get_right(), to_edit);
    return 1;
}

// WRAPPER: remove this health_event 
void BST::remove(string& to_find)
{
    if (!root) return;
//    health_event* to_remove = search_name(to_find);
//    if (!to_remove) return;
    return remove(root, to_find);
}

// RECURSIVE: remove this health_event
//void BST::remove(unique_ptr<node>& root, health_event*& to_remove)
void BST::remove(unique_ptr<node>& root, string &to_find)
{
    if (!root) return;

    if (root->compare_name(to_find) == true)
    {
	// delete root
	if (root->get_left() == nullptr && root->get_right() == nullptr)
	{
	    cout << "event is the root" << endl;
	    root.reset();
	    root = nullptr;
	    return;
	}
	// delete parent and adopt IOS
	// parent with left child
	else if (root->get_left() != nullptr && root->get_right() == nullptr)
	{
	    cout << "Parent with one left child" << endl;
	    unique_ptr<node> hold = move(root->get_left());
	    root.reset();
	    root = move(hold);
	    return;
	}
	// parent with right child
	else if (root->get_left() == nullptr && root->get_right() != nullptr)
	{
	    cout << "parent with one right child" << endl;
	    unique_ptr<node> hold = move(root->get_right());
	    root.reset();
	    root = nullptr;
	    root = move(hold);
	    return;
	}
	// parent with two children
	// find IOS
	else
	{
	    // if node has immediate IOS
	    if (root->get_right()->get_left() == nullptr)
 	    {
		root->set_health_event(root->get_right()->get_health_event());
		if (root->get_right()->get_right() != nullptr)
		{
		    unique_ptr<node> hold = move(root->get_right()->get_right());
		    root->get_right().reset();
		    root->get_right() = move(hold);
		    cout << "This event is a direct relation." << endl;
		    return;
		}
	    } 
	    else
	    {
		unique_ptr<node> parent = move(root);
		unique_ptr<node> curr = move(root->get_right());

		// traverse to smallest value in right subtree
		while (curr->get_left())
		{
			parent = move(curr);
			curr = move(curr->get_left());
		}
		// set root to the event we want to remove
		root->set_health_event(curr->get_health_event());

		// resolve cases for removing curr
		if (curr->get_right() != nullptr)
		{
		    unique_ptr<node> hold = move(curr->get_right());
		    parent->set_left(move(hold));
		    curr.reset();
		    curr = nullptr;
		    cout << "Item is not related, right attached." << endl;
		    return;
		}
		// otherwise curr is a leaf
		else
		{
		    curr.reset();
		    curr = nullptr;
		    parent->set_left(nullptr);
		    return;
		}
            }
	 }
    }
    remove(root->get_left(), to_find);
    remove(root->get_right(), to_find);
    return;
}

// WRAPPER: remove all the health_events in the tree
int BST::remove_all(void)
{
    // apply exception handling here
    if (!root) return 0;
    return remove_all(root);
}

// RECURSIVE: remove all the health_events in the tree
int BST::remove_all(unique_ptr<node>& root)
{
    int count {0};

    if (!root) return count;
    count += remove_all(root->get_left());
    count += remove_all(root->get_right());
    root.reset();
    root = nullptr;
    return count;
}

