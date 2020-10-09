.PHONY : all clean

cc = g++
include = ../Include

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %, $(src))

all : $(obj)

% : %.cc
	$(cc) -o $@ $^ -g -Wall -pthread -I $(include)

clean:
	rm -rf $(obj)
