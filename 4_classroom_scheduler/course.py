# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#     the course class will build a course with the classroom object
#      returned from classroom_reservation().  We will also include
#           instructor name, CRN, course name, and time_block.
# -------------------------------------------------------------------------

class course():
    def __init__(self, class_obj, prof_name, course_name, course_num, day, a_time):
        self._classroom_obj = class_obj
        self._course_name = course_name
        self._prof_name = prof_name
        self._CRN = course_num
        self._course_day = day
        self._time_block = a_time

    @property
    def room_obj(self):
        return self._classroom_obj
    @room_obj.setter
    def room_obj(self, new_obj):
        self._classroom_obj = new_obj
        
    @property
    def prof_name(self):
        return self._prof_name
    @prof_name.setter
    def prof_name(self, new_name):
        self.prof_name = new_name
      
    @property
    def course_name(self):
        return self._course_name
    @course_name.setter
    def course_name(self, new_name):
        self._course_name = new_name

    @property
    def CRN(self):
        return self._CRN
    @CRN.setter
    def CRN(self, new_num):
        self._CRN = new_num
       
    @property
    def time_block(self):
        return self._time_block
    @time_block.setter
    def time_block(self, new_time):
        self._time_block = new_time

    # op overload >
    def __gt__(self, other):
        this_CRN = self._CRN
        other_CRN = other.CRN  
        return this_CRN > other_CRN

    # op overload >=
    def __ge__(self, other):
        this_CRN = self._CRN
        other_CRN = other.CRN
        return this_CRN >= other_CRN

    # op overload <
    def __lt__(self, other):
        this_CRN = self._CRN
        other_CRN = other.CRN
        return this_CRN < other_CRN

    # op overload <=
    def __le__(self, other):
        this_CRN = self._CRN
        other_CRN = other.CRN
        return this_CRN <= other_CRN

    # display the course object
    def display(self):
        print("CRN:", self._CRN)
        print("Course:", self._course_name)
        print("Instructor:", self._prof_name)
        print("Room: FAB", self._classroom_obj._room_num)
        print("Day(s):", self._course_day)
        print("Time:", self._time_block)
        if (self._classroom_obj.handi_accessible == True):
            print("Access: Handicap Accessible")
        else: 
            print("Access: Not Handicap Accessible")
        
