from classrooms import classroom
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#        lab_room is a derived class of the classroom hierarchy 
# -------------------------------------------------------------------------
# lab_room is a derived classroom
class lab_room(classroom):
    def __init__(self, new_room, new_seats, handi_accessible, 
                 is_reserved, computers):
        super().__init__(new_room, new_seats, handi_accessible, is_reserved)
        self._num_computers = computers
        self._type = "Lab Room"

    @property
    def computers(self):
        return self._num_computers
    @computers.setter
    def computers(self, new_num):
        self._num_computers = new_num

    @property
    def type(self):
        return self._type
    # @type.setter
    # def type(self, new_type):
    #     self._type = new_type

    def edit(self):
        choice = 0
        while choice >= 0 and choice <= 6:
            print("\n=========== EDIT LAB ROOM ===========\n")
            print("\t[1] Room Number \n\t[2] Number of Seats \n\t[3] Handicap Access \
                \n\t[4] Reserved \n\t[5] Number of Computers \n\t[6] Exit\n")
            choice = int(input("Selection: "))
            if choice == 1 or choice == 2 or choice == 3 or choice == 4:
                super().edit(choice)
            elif (choice == 5):
                choice = int(input("How Many Computers?: "))
            elif (choice == 6):
                return
            else:
                print("Please enter a number between 1-5.")

    def display(self):
        print("------------- LAB ROOM -------------")
        super().display()
        print("# Computers:", self._num_computers)
        return