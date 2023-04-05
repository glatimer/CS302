from classrooms import classroom
from course import course
from application import application
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#  This file is responsible for the client experience of our software
# -------------------------------------------------------------------------
if __name__ == "__main__":
    app = application()
    room_obj = classroom(0,0,False, False)
    course_obj = course(room_obj, 0, 0, 0, 0, 0)
    response = -1

    # setup the classroom database by prepopulating the building
    app.populate_building()
    app.populate_courses()
    
    while (response != 5):
        # greeting/menu options for instructor
        response = app.greeting(1)
            
        # [1] Display all classrooms
        if (1 == response):
            app.display_all()
            
        # [2] Add Course
        elif (2 == response):
            del room_obj
            del course_obj
            room_obj = app.classroom_reservation()
            if None == room_obj:
                # not found
                print("Classroom was NOT reserved.\n")
            else: 
                # available classroom was found
                print("\nWe found an available classroom for your criteria\n")
                room_obj.display()
                print("\n\n")

                # collect course information
                course_obj = app.course_input(room_obj)

                # add the course to the tree
                app.add_course(course_obj)


        # [3] Display One Course (tree)
        elif (3 == response):
            print("----------------------------------------------------")
            print("              2023 Spring Term Course               ")
            print("----------------------------------------------------")
            app.retrieve_course()

        # [4] Display All Course Offerings (tree)
        elif (4 == response):
            print("-------------------------------------------------------------")
            print("                 Spring 2023 Course Offerings                ")
            print("-------------------------------------------------------------")
            app.display_offerings()

        # [5] Exit
        elif (5 == response):
            app.greeting(2)
            exit

        # Not an Option
        else:
            print("Please, enter a number from 1-4.\n")
