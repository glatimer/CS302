# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#     This file contains the implementation for a linear linked list
# -------------------------------------------------------------------------

# node class
class Node():
    def __init__(self, object):
        self._data = object
        self._next = None
    def __del__(self):
        self._next = None
    def set_next(self, new_next):
        self._next = new_next
    def get_next(self):
        return self._next
    def display(self):
        self._data.display()

# linear linked list class
class LLL():
    #default constructor
    def __init__(self):
        self._head = None

    # wrapper for inserting a new node
    def insert(self, new_classroom):
        if None == new_classroom: return None
        self._head = self._insert_sorted(self._head, new_classroom)

    # recursive insert ordered by seat number
    def _insert_sorted(self, head, new_classroom):
        temp = Node(new_classroom)
        
        # first node
        if head == None:
            head = temp
            return head
        # base case, insert
        if head.get_next() == None:
            if new_classroom.seat_number >= head._data.seat_number:
                head.set_next(temp)
            if new_classroom.seat_number < head._data.seat_number:
                temp.set_next(head)
                head = temp
            return head
        head.set_next(self._insert_sorted(head.get_next(), new_classroom))
        return head

    # wrapper to dislpay the LLL
    def display(self):
        self.list_display(self._head)

    # display the LLL
    def list_display(self, head):
        while head != None:
            head.display()
            head = head.get_next()
  
    # wrapper to search the LLL for the requested seat number and type
    def find_availability(self, classroom_obj):
        if self._head == None: return None
        self._head = self._find_availability(self._head,classroom_obj)
        
    # recursive search the LLL for the requested seat number and type
    def _find_availability(self, head, classroom_obj):
        match = False
        if head == None:
            print("\n============== No Availability ===============")
            print("  For a", classroom_obj.type, "with", classroom_obj.seat_number, "requested seats.\n")
            return None
        # if we find a room that matches and is not reserved, reserve it
        if head._data.seat_number == classroom_obj.seat_number and \
           head._data.type == classroom_obj.type and \
           head._data.handi_accessible == classroom_obj.handi_accessible and \
           head._data.is_reserved == False: 
            if classroom_obj.type == "Standard Room":
                if head._data.monitors == classroom_obj.monitors: 
                    match = True
            elif classroom_obj.type == "Zoom Room":
                if head._data.cameras == classroom_obj.cameras and \
                   head._data.mic == classroom_obj.mic:
                    match = True
            elif classroom_obj.type == "Lab Room":
                if head._data.computers == classroom_obj.computers:
                    match = True
            if match == True:
                print("\n================ Availability ================")
                print("Room Number:", head._data._room_num, "\n")
                head._data.display()
                head._data.reserve_room(1)
                classroom_obj.room_number = head._data._room_num
                classroom_obj._reserved = head._data._reserved
                return head
        return head.set_next(self._find_availability(head.get_next(), classroom_obj))
  