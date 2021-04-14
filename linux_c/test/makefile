.PHONY : all clean

cc = g++
include = ../Include

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %, $(src))

all : $(obj)

% : %.cc
	gcc -o $@ $^ -g

clean:
	rm -rf $(obj)

