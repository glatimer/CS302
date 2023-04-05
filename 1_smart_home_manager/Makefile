# ===============================================================================
#		       CS302 Assignment 1 - Genevieve Latimer
# -------------------------------------------------------------------------------
#    I'm learning how to implement make files in another class and I wanted
# 	          to try applying what I know to this assignment.  
# =============================================================================== */

CC = g++ 
DEBUG = -g
RM = rm -f
# DEFINES = I dont have any at the moment
CFLAGS =  -std=c++17 -Wall 

main: main.o devices.o schedule.o network.o
	$(CC) $(DEBUG) main.o devices.o schedule.o network.o -o main

devices.o: devices.cpp
	$(CC) $(CFLAGS) -c devices.cpp

schedule.o: schedule.cpp
	$(CC) $(CFLAGS) -c schedule.cpp

network.o: network.cpp
	$(CC) $(CFLAGS) -c network.cpp

clean:
	$(RM) test *.o *~D
