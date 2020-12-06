.PHONY : all clean

cc = g++
include = ../Include

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %, $(src))

all : $(obj)

% : %.cc
	$(cc) -o $@ $^ `pkg-config --cflags --libs opencv4` -std=c++11 -g -Wall

clean:
	rm -rf $(obj)
