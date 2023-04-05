#ifndef DLL_H
#define DLL_H
#include <memory>
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
using std::shared_ptr;

template <typename TYPE>
class node
{
    public:
    typedef shared_ptr<node<TYPE>> node_ptr_type;

    node<TYPE>(void);
    node<TYPE>(const TYPE &new_data);
    node<TYPE>(const node_ptr_type &to_copy);
    node<TYPE>& operator=(const TYPE &source);
    ~node<TYPE>(void);
    node_ptr_type& get_next(void);
    node_ptr_type& get_prev(void);
    void set_next(node_ptr_type new_next);
    void set_prev(node_ptr_type new_prev);
    TYPE get_data() const;
    int set_data(const TYPE& to_add);
    int display(void) const;

    private:
    TYPE data;
    node_ptr_type next;
    node_ptr_type prev;
};


template <typename TYPE>
class DLL
{
    public:
    typedef shared_ptr<node<TYPE>> node_ptr_type;

    DLL(void);
    DLL(const DLL& to_copy);
    DLL& operator=(const DLL& source);
    int insert(const TYPE& to_add);
    int display(void) const;
    
    private:
    node_ptr_type head;
    node_ptr_type tail;

    // recursive functions
    int insert(node_ptr_type &head, const TYPE &to_add);
    int display(const node_ptr_type &head) const;

};
#include "DLL.ipp"
#endif
