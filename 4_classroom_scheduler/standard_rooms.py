from classrooms import classroom
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#        standard_room is a derived class of the classroom hierarchy 
# -------------------------------------------------------------------------
# standard_room is a derived classroom
class standard_room(classroom):
    def __init__(self, new_room, new_seats, handi_accessible, 
                 is_reserved, monitors):
        super().__init__(new_room, new_seats, handi_accessible, is_reserved)
        self._num_monitor = monitors
        self._type = "Standard Room"
    
    @property
    def monitors(self):
        return self._num_monitor
    @monitors.setter
    def monitors(self, input):
        self._num_monitor = input

    @property
    def type(self):
        return self._type
    # @type.setter
    # def type(self, new_type):
    #     self._type = new_type

    def edit(self):
        choice = 0
        while choice >= 0 and choice <= 6:
            print("\n=========== EDIT STANDARD ROOM ===========\n")
            print("\t[1] Room Number \n\t[2] Number of Seats \n\t[3] Handicap Access \
                 \n\t[4] Reserved \n\t[5] Number of Monitors \n\t[6] Exit\n")
            choice = int(input("Selection: "))
            if choice == 1 or choice == 2 or choice == 3 or choice == 4:
                super().edit(choice)
            elif (choice == 5):
                choice = int(input("How Many Monitors?: "))
            elif (choice == 6):
                return
            else:
                print("Please enter a number between 1-5.")
    
    def display(self):
        print("------------- STANDARD ROOM -------------")
        super().display()
        print("# Monitors:", self._num_monitor)
        return

