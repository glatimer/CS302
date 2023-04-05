import numpy as np
from linked_list import LLL
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#         This file contains the implementation for an array
#                        of linear linked lists 
# -------------------------------------------------------------------------
# create a numpy array of classrooms in building (aka FAB)
# organized by hierarchy categories
# [0 standard ] -> [015] -> [101] -> [201] -> ... -> [215]-> NULL 
# [1 zoom     ] -> [150] -> [155] -> [205] -> ... -> [210]-> NULL
# [2 lab      ] -> [033] -> [075] -> [105] -> ... -> [175]-> NULL

class ARR_LLL:
    def __init__(self):
        self._count = 0
        # LLLs
        list_standard = LLL()
        list_zoom = LLL()
        list_lab = LLL()

        # initialize ARR_LLL
        self.arr = np.array([list_standard, list_zoom, list_lab])
                
    # insert takes a classroom object as an argument
    # and inserts it into the ARR_LLL as a Node
    def classroom_insert(self, classroom_object):
        # # if type == "Standard Room" insert into array[0]
        if (classroom_object.type == "Standard Room"):
            self.arr[0].insert(classroom_object)
            self._count += 1
        # if type == "Zoom Room" insert into array[1]
        if (classroom_object.type == "Zoom Room"):
            self.arr[1].insert(classroom_object)
            self._count += 1
        # if type == "Lab Room" insert into array[2]
        if (classroom_object.type == "Lab Room"):
            self.arr[2].insert(classroom_object)
            self._count += 1
        
    # display the entire ARR_LLL
    def display_all(self):
        self.arr[0].display()
        self.arr[1].display()
        self.arr[2].display()
        print("\nThere are", self._count, "classrooms.\n")

    # pass in the type and # seats 
    # to see if we find availability 
    def search(self, classroom_obj):
        if ("Standard Room" == classroom_obj.type):
            self.arr[0].find_availability(classroom_obj)

        if ("Zoom Room" == classroom_obj.type):
            self.arr[1].find_availability(classroom_obj)

        if ("Lab Room" == classroom_obj.type):
            self.arr[2].find_availability(classroom_obj)

    # search the list by room number
    def display_one(self, room_number):
        pass