#________________________________________________________________________ 
#   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
#|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
#   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
#------------------------------------------------------------------------
#		CS302 Assignment #2 - Genevieve Latimer
#  	     Makefile will handle C++ compiling information  
#------------------------------------------------------------------------ 

CC = g++ 
DEBUG = -g
RM = rm -f
# DEFINES = I dont have any at the moment
CFLAGS = $(DEBUG) -std=c++17 -Wall -c 

test: main.o health_event.o BST.o app.o
	$(CXX) $(DEBUG) main.o health_event.o BST.o app.o

health_event.o: health_event.cpp
	$(CXX) $(CFLAGS) health_event.cpp

BST.o: BST.cpp
	$(CXX) $(CFLAGS) BST.cpp

app.o: app.h
	$(CXX) $(CFLAGS) app.cpp

clean:
	$(RM) test *.o *~D

DIR = $(shell basename $(PWD))
canvas:
	make clean
	cd .. ; tar --exclude-backups --exclude-vcs -c -a -f ./${LOGNAME}-$(DIR).tar.gz $(DIR)

ci:
	if [ ! -d RCS ] ; then mkdir RCS; fi
	ci -t-none -m"lazy-checkin" -l *.[chS] *.pl *.ld ?akefile

git:
	if [ ! -d .git ] ; then git init; fi
	git add *.[chS] *.pl *.ld ?akefile
	git commit -m "Program #2 updated (lazy commit)"
#________________________________________________________________________ 
#   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
#|||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
#   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||   |||
#------------------------------------------------------------------------ 
