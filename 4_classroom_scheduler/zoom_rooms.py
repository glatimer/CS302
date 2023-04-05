from classrooms import classroom
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#        zoom_room is a derived class of the classroom hierarchy 
# -------------------------------------------------------------------------

# zoom_room is a derived classroom
class zoom_room(classroom):
    # param constructor
    def __init__(self, new_room, new_seats, handi_accessible, 
                 is_reserved, cameras, mic):
        super().__init__(new_room, new_seats, handi_accessible, is_reserved)
        self._num_cameras = cameras
        self._num_mic = mic
        self._type = "Zoom Room"
    
    # get/set the number of cameras
    @property 
    def cameras(self):
        return self._num_cameras
    @cameras.setter
    def cameras(self, camera):
        self._num_cameras = camera

    # get/set the number of mics
    @property
    def mic(self):
        return self._num_mic
    @mic.setter
    def mic(self, mics):
        self._num_mic = mics

    @property
    def type(self):
        return self._type
    # @type.setter
    # def type(self, new_type):
    #     self._type = new_type

    # # compare room number to an int input
    # def compare_room_num(self, to_compare):
    #     super().compare_room_num(to_compare)

    def edit(self):
        choice = 0
        while choice >= 0 and choice <= 7:
            print("\n=========== EDIT ZOOM ROOM ===========\n")
            print("\t[1] Room Number \n\t[2] Number of Seats \n\t[3] Handicap Access \
                 \n\t[4] Reserved \n\t[5] Number of Cameras \n\t[6] Number of Microphones \
                 \n\t[7] Exit\n")
            choice = int(input("Selection: "))
            if choice == 1 or choice == 2 or choice == 3 or choice == 4:
                super().edit(choice)
            elif (choice == 5):
                choice = int(input("How Many Cameras?: "))
            elif (choice == 6):
                choice = int(input("How Many Microphones?: "))
            elif (choice == 7):
                return
            else:
                print("Please enter a number between 1-6.")

    def display(self):
        print("------------- ZOOM ROOM -------------")
        super().display()
        print("# Cameras:", self._num_cameras)
        print("# Microphones:", self._num_mic)
        return