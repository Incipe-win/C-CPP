.PHONY : all clean

cc = arm-none-linux-gnueabi-g++
include = /opt/opencv3.2/include

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %, $(src))

all : $(obj)

% : %.cc
	$(cc) -o $@ $^ -I ${include} `pkg-config --cflags --libs opencv` -std=c++11 -g -Wall -lz

clean:
	rm -rf $(obj)
