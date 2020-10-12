all : app

cc = g++
include = ../Include

.PHONY : clean all

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %.o, $(src))

app : $(obj)
	ar -crv libstaticapp.a $(obj)

%.o : %.cc
	$(cc) -c $< -I $(include) -o $@

clean:
	rm -f *.o
	rm -f app

