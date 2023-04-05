# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#        the classroom class is the base class of the hierarchy 
# -------------------------------------------------------------------------

class classroom:
    # param constructor
    def __init__(self, new_room, new_seats, 
                 handi_accessible, is_reserved):
        self._room_num = new_room
        self._num_seats = new_seats
        self._handi_access = handi_accessible
        self._reserved = is_reserved
        self._type = "Classroom"
    
    # room number get/set
    @property
    def room_number(self):
        return self._room_num
    @room_number.setter
    def room_number(self, room_num):
        self._room_num = room_num

    # number of seats get/set
    @property
    def seat_number(self):
        return self._num_seats
    @seat_number.setter
    def seat_number(self, num_seats):
        self._num_seats = num_seats

    # handicap accessible get/set
    @property
    def handi_accessible(self):
        return self._handi_access
    @handi_accessible.setter
    def handi_accessible(self, handi_accessible):
        self._handi_access = handi_accessible

    # reserved get/set
    @property
    def is_reserved(self):
        return self._reserved
    @is_reserved.setter
    def handi_accessible(self, reserved):
        self._reserved = reserved

    @property
    def type(self):
        return self._type
    # @type.setter
    # def type(self, new_type):
    #     self._type = new_type

     # op overload >
    def __gt__(self, other):
        this_room_num = self._room_num
        other_room_num = other.room_number  
        return this_room_num > other_room_num

    # op overload >=
    def __ge__(self, other):
        this_room_num = self._room_num
        other_room_num = other.room_number
        return this_room_num >= other_room_num

    # op overload <
    def __lt__(self, other):
        this_room_num = self._room_num
        other_room_num = other.room_number
        return this_room_num < other_room_num

    # op overload <=
    def __le__(self, other):
        this_room_num = self._room_num
        other_room_num = other.room_number
        return this_room_num <= other_room_num
    
    # compare room number to an int input
    def compare_room_num(self, to_compare):
        if self._room_num == to_compare:
            return True
        else:
            return False
        
    # edit the object
    def edit(self, choice):
        if choice == 1:
            self._room_num = int(input("New Room Number: "))
        elif choice == 2:
            self._num_seats = int(input("New Total Seats: "))
        elif choice == 3:
            print("Is the room: \
                  \n\tHandicap Accesible [True] \
                  \n\tNot Handicap Accessible [False]")
            self._handi_access = input("\n\tAnswer: ")
        elif choice == 4:
            print("Is the room: \
                  \n\tReserved [True] \
                  \n\tNot Reserved [False]")
            self._reserved = input("\n\tAnswer: ")

    def display(self):
        print("Room: FAB", self._room_num)
        print("# Seats:", self._num_seats)
        print("Handicap Accessible:", self._handi_access)
        print("Reserved:", self._reserved)

    # same function to reserve or release a room number
    def reserve_room(self, choice):
        if 1 == choice:
            self._reserved = True
        if 2 == choice:
            self.reserved = False