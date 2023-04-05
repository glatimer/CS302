#ifndef DLL_IPP
# define DLL_IPP
#include "DLL.h"
#include <iostream>
/*______________________________________________________________________ 
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
------------------------------------------------------------------------
		CS302 Assignment #2 - Genevieve Latimer
 	DLL.h will contain the definitions and methods for the 
    doubly linked list class and its node class. We are attempting 
	to use templates for this data structure so that we can 
	 use any data type interchangably. Also, attempting to 
	  use shared pointers to deal with memory management.
----------------------------------------------------------------------- */

using namespace std;
template <typename TYPE>
using node_ptr_type = shared_ptr<node<TYPE>>;
using std::cout;
using std::endl;


// -------------------------- NODE CLASS -----------------------------
// default constructor
template <typename TYPE>
node<TYPE>::node(void):  next(nullptr), prev(nullptr) {}

// param constructor
template <typename TYPE>
node<TYPE>::node(const TYPE &new_data): data(new_data), next(nullptr), prev(nullptr) {}

// copy constructor
template <typename TYPE>
node<TYPE>::node(const node_ptr_type &to_copy)
//node<TYPE>::node(const TYPE &to_copy)
{
    data = to_copy;
    next = make_shared<node<TYPE>>(*to_copy.next);
    prev = make_shared<node<TYPE>>(*to_copy.prev);
}

// assignment operator
template <typename TYPE>
node<TYPE>& node<TYPE>::operator=(const TYPE& source)
{
    // check for self assignment
    if (this == &source) return *this;

    if (data) delete data;
    data = source.data;
    next = make_shared<node<TYPE>>(*source.next);
    prev = make_shared<node<TYPE>>(*source.prev);

    return *this;
}

// destructor
template <typename TYPE>
node<TYPE>::~node<TYPE>(void)
{
    next.reset();
    prev.reset();
}

// getter
template <typename TYPE>
//typename node<TYPE>::node_ptr_type& node<TYPE>::get_next(void)
shared_ptr<node<TYPE>>& node<TYPE>::get_next(void) 
{
    return next;
}

// getter
template <typename TYPE>
shared_ptr<node<TYPE>>& node<TYPE>::get_prev(void) 
{
    return prev;
}

// setter
template <typename TYPE>
void node<TYPE>::set_next(node_ptr_type new_next)
{
    next = new_next;

}

// setter
template <typename TYPE>
void node<TYPE>::set_prev(node_ptr_type new_prev)
{
    prev = new_prev;
}

// get object data
template <typename TYPE>
TYPE node<TYPE>::get_data() const
{
    return data;
}

// set object data?
template <typename TYPE>
int node<TYPE>::set_data(const TYPE& to_add)
{
    //TYPE(to_add);
    return 0;
}

// display object
template <typename TYPE>
int node<TYPE>::display(void) const
{
    //data.display();
    cout << data << endl;
    return 0;
}


// --------------------------- DLL CLASS -----------------------------
// default constructor
template <typename TYPE>
DLL<TYPE>::DLL(void): head(nullptr), tail(nullptr) {}

// copy constructor
template <typename TYPE>
DLL<TYPE>::DLL(const DLL& to_copy)
{
}

// assignment operator
template <typename TYPE>
DLL<TYPE>& DLL<TYPE>::operator=(const DLL& source)
{
    // check for self assignment
    if (this == &source) return *this;

    head = move(source.head);
    tail = move(source.tail);
    // assign new list

    return *this;
}

// insert a node
template <typename TYPE>
int DLL<TYPE>::insert(const TYPE& to_add) 
{
    return insert(head, to_add);
}

// recursive insert
template <typename TYPE>
int DLL<TYPE>::insert(node_ptr_type &head, const TYPE &to_add)
{
    // new node to insert
    shared_ptr<node<TYPE>> temp = make_shared<node<TYPE>>(to_add);

    // if the list is empty, add head
    if (!head)
    {
	temp->set_next(nullptr);
	temp->set_prev(nullptr);
	head = temp;
	tail = head;
	return 1;
    }
    // if we exhaust the list without identifying a spot, add at tail
    else if (head == tail)
    {
	temp->set_prev(tail);
	temp->set_next(nullptr);
	tail->set_next(temp);
	tail = temp;
	return 1;
    }
    return insert(head->get_next(), to_add);
}

// display list
template <typename TYPE>
int DLL<TYPE>::display(void) const
{
    if (!head) return 0;
    return display(head);
}

// recursive display
template <typename TYPE>
int DLL<TYPE>::display(const node_ptr_type &head) const
{
    int count {0};
    if (!head) return count;
    if (head == tail)
    {
        head->display();
	return count;
    }
    head->display();
    return count += display(head->get_next()) + 1;
}



#endif // DLL_H
