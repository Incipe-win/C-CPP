all : hello world

cc = g++
include = ../Include

.PHONY : all clean

hello : hello.o
	$(cc) -o hello -I $(include) hello.o

world : world.o
	$(cc) -o world -I $(include) world.o

hello.o : hello.cc
	$(cc) -c hello.cc -I $(include)

world.o : world.cc
	$(cc) -c world.cc -I $(include)

clean :
	rm -f *.o
	rm -f hello world

