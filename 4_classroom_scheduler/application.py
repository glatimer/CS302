from standard_rooms import standard_room
from zoom_rooms import zoom_room
from lab_rooms import lab_room
from classrooms import classroom
from Array_LLL import ARR_LLL
from course import course
from two_three_tree import Node
from two_three_tree import Two_Three_Tree
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#     This file contains the implementation for a the application
#   that will navigate user input, decision making, and searching the
#   ARR_LLL for availability.  If the room is available, reserve it 
#   and add it to the course tree.  If not, respond with a message.  
# -------------------------------------------------------------------------

class application:
    def __init__(self):
        # initialize objects
        self._standard = standard_room(0, 0, False, False, 0)
        self._zoom = zoom_room(0, 0, False, False, 0, 0)
        self._lab = lab_room(0, 0, False, False, 0)
        self._FAB = ARR_LLL()
        self._room_obj = classroom(0, 0, False, False)
        self._spring_term = Two_Three_Tree()

    # prepopulate ARR_LLL of classrooms
    def populate_building(self):
        # insert standard classrooms
        with open('standard_rm.txt', 'r') as f:
            for line in f:
                data = line.strip().split(', ')
                if data[2] == "True": handi = True
                elif data[2] == "False": handi = False
                if data[3] == "True": reserve = True
                elif data[3] == "False": reserve = False
                classroom = standard_room(int(data[0]), int(data[1]), handi, reserve, int(data[4]))
                self._FAB.classroom_insert(classroom)
        # insert zoom classrooms 
        with open('zoom_rm.txt', 'r') as f:
            for line in f:
                data = line.strip().split(', ')
                if data[2] == "True": handi = True
                elif data[2] == "False": handi = False
                if data[3] == "True": reserve = True
                elif data[3] == "False": reserve = False
                classroom = zoom_room(int(data[0]), int(data[1]), handi, reserve, int(data[4]), int(data[5]))
                self._FAB.classroom_insert(classroom)
        # insert lab classrooms 
        with open('lab_rm.txt', 'r') as f:
            for line in f:
                data = line.strip().split(', ')
                if data[2] == "True": handi = True
                elif data[2] == "False": handi = False
                if data[3] == "True": reserve = True
                elif data[3] == "False": reserve = False

                classroom = lab_room(int(data[0]), int(data[1]), handi, reserve, int(data[4]))
                self._FAB.classroom_insert(classroom)

    # greeting and menu options for instructor
    def greeting(self, choice):
        response = -1

        # open greeting
        if 1 == choice:
            print("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *")
            print("-----------------------------------------------------------")
            print("       Welcome to PSU's Course Scheduler Software          ")
            print("-----------------------------------------------------------")
            print("\n[1] Display All Classrooms (arr_lll) \
                   \n[2] Add Your Course to Course Offerings (tree)\
                   \n[3] Display One Course Offering (tree) \
                   \n[4] Display All Course Offerings (tree) \
                   \n[5] Exit\n")
            response  = int(input("Selection: "))
            return response

        # closing greeting
        if 2 == choice:
            print("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *")
            print("-----------------------------------------------------------")
            print("     Thanks for using PSU's Course Scheduler Software      ")
            print("-----------------------------------------------------------")
            print("                  Have a great Term!                       ")

        print("___________________________________________________________")
        print("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *")
        
       
    # display all of the classrooms in the building
    def display_all(self):
        self._FAB.display_all()

    # gather search criteria into an object 
    # return the object 
    def collect_data(self, room_type):
        print("\nClassroom Seat Number Options: \
             \n[1] 40 seats \
             \n[2] 60 seats \
             \n[3] 90 seats \
             \n[4] 120 seats ")
        response = int(input("Number of Seats Requested: "))
        if 1 == response: number_seats = 40
        elif 2 == response: number_seats = 60
        elif 3 == response: number_seats = 90
        elif 4 == response: number_seats = 120
        else: print("Not an Option\n")
        
        print("\n[1] Handicap Access Necessary \
               \n[2] Not Required\n")
        response = int(input("Handicap Access Requested: "))
        if 1 == response: handi_access = True
        elif 2 == response: handi_access = False
        else: print("Not an Option\n")

        # standard room
        if 1 == room_type: 
            print("Classroom Monitor Options: \
             \n[1] 1 monitor \
             \n[2] 2 monitors")
            monitors = int(input("Number of Monitors Requested: "))
            self._room_obj = standard_room(0, number_seats, handi_access, False, monitors)

        # zoom room
        elif 2 == room_type: 
            print("Classroom Camera Options: \
                \n[1] 1 camera \
                \n[2] 2 cameras")
            cameras = int(input("Number of Cameras Requested: "))
            print("\nClassroom Microphone Options: \
                \n[1] 1 Microphone \
                \n[2] 2 Microphones")
            mics = int(input("Number of Microphones Requested: "))
            self._room_obj = zoom_room(0, number_seats, handi_access, False, cameras, mics)

        # lab room
        elif 3 == room_type: 
            print("Classroom Computer Options: \
                \n[1] 20 computers \
                \n[2] 40 computers \
                \n[3] 60 computers")
            response = int(input("Number of Student Computers Requested: "))
            if 1 == response: computers = 20
            elif 2 == response: computers = 40
            elif 3 == response: computers = 60
            else: print("Not an option\n")
            self._room_obj = lab_room(0, number_seats, handi_access, False, computers)
        else: print("Not an Option\n")
        return self._room_obj

    # gather classroom information and search for a match
    def classroom_reservation(self):
        while self._room_obj.room_number == 0:
            print("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *")
            print("-----------------------------------------------------------")
            print("              Find the Required Classroom                  ")
            print("-----------------------------------------------------------")
            print("Classroom Descriptions: \
                \n[1] Standard Room = standard room with monitors \
                \n[2] Zoom Room = standard room cameras, and microphones \
                \n[3] Lab Room = standard room with student computers")
            room_type = int(input("Select a Room Type: "))

            self._room_obj = self.collect_data(room_type)
            self._FAB.search(self._room_obj)

            if (self._room_obj.room_number == 0):
                print("No match was found")
                print("\t[1] Try Again \
                     \n\t[2] Exit\n")
                choice = int(input("Selection: "))
                if 2 == choice:
                    return None
            else:        
                return self._room_obj

        print("___________________________________________________________")
        print("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *")


    # prepopulate 2-3 tree of courses
    def populate_courses(self):
        # hard code some objects
        lab1 = lab_room(203, 90, True, True, 20)
        lab2 = lab_room(207, 40, True, True, 20)
        lab3 = lab_room(220, 90, True, True, 20)
        lab4 = lab_room(245, 60, True, True, 40)
        lab5 = lab_room(280, 90, True, True, 20)
        lab6 = lab_room(295, 90, False, True, 20)
        standard1 = standard_room(95, 60, False, True, 2)
        standard2 = standard_room(100, 90, True, True, 2)
        standard3 = standard_room(105, 120, True, True, 2)
        standard4 = standard_room(109, 120, True, True, 2)
        standard5 = standard_room(125, 120, False, True, 2)
        standard6 = standard_room(135, 60, False, True, 2)
        zoom1 = zoom_room(155, 90, True, True, 2, 2)
        zoom2 = zoom_room(170, 90, True, True, 2, 2)
        zoom3 = zoom_room(100, 90, False, True, 2, 2)
        obj_list = [standard1, standard2, standard3, standard4, standard5, standard6
                    , lab1, lab2, lab3, lab4, lab5, lab6
                    , zoom1, zoom2, zoom3]
        
        # insert standard classrooms
        i = 0
        with open('courses.txt', 'r') as f:
            for line in f:
                data = line.strip().split('|')
                course_obj = course(obj_list[i], data[0], data[1], int(data[2]), data[3], data[4])
                self._spring_term.insert(course_obj)
                i += 1

    # build a course object
    def course_input(self, room_obj):
        instructor = input("Instructor: ")
        course_name = input("Course Name: ")
        CRN_num = int(input("CRN: "))
        days = input("Day(s) of the Week: ")
        time_block = input("Time: ")
        
        c_obj = course(room_obj, instructor, course_name, CRN_num, days, time_block)
        return c_obj

    # if a match is found, build a 2-3 tree node containing that object
    # insert the node into the 2-3 tree sorted by room number
    def add_course(self, course_obj):
        self._spring_term.insert(course_obj)

    # retrieve and display a course in the tree
    def retrieve_course(self):
        print("What is the CRN of the course you would like to find?")
        CRN_num = int(input("CRN: "))
        self._spring_term.search(CRN_num)
 
    # display all offerings
    def display_offerings(self):
        self._spring_term.display_tree()