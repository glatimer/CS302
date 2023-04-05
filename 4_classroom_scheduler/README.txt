-------------------------------------------------------------------------
                 Assignment #4-5 : Genevieve Latimer
                             README 
-------------------------------------------------------------------------
ABOUT THE PROGRAM:
This program is a classroom reservation and course scheduler.
The program will begin with a prepopulated:
    - "FAB building" (ARR_LLL)
    - "Spring Term" (2-3 tree)

The application class will:
    SCHEDULE CLASSROOM: 
    1) Get classroom requirements.
    2) Search for an available classroom.
    3) NOT AVAILABLE -> Ask the user to try again or quit.
    4) AVAILABLE -> Reserve it and return classroom details 
                    to the application to be inserted into 
                    the course tree.
    ADD COURSE:
    5) Get course details and build a course object.
    6) Insert course object into the 2-3 tree sorted by CRN number.
        
    APPLICATION MENU OPTIONS:
    [1] Display all the classrooms
    [2] Add Course
    [3] Display One Course
    [4] Display All Courses
    [5] Exit

TESTING MANUAL ADD (menu option 2)
2, 1, 1, 1, 1 is available 
3, 4, 1, 3 is not available

or you could display Classrooms to see a room
criteria that you want to enter

The Course tree is displayed in order, so an easy 
way to find your inputted course would be to use 
CRN: 1
CRN: 10000

*Note* Unfortunately, you can't add more than one course.  
I tried clearing the object to be used again, but I 
ran out of time to problem solve that one.

PYTEST TESTING
Note: I have a few interactive functions in the hierarchy 
      that I was not able to hardcode variables for testing.
      Because of this, you will need to run pytest with -s flag
      and insert answers along the way. You will not be able to 
      insert just any input.  For the test to work:
        * ints = 102
        * booleans = True
REMINDER:
[1] Be sure to run pytest -s in the command line
[2] I tried to streamline everyting with the same input
    - ints = 102
    - bools = True

