all : app

cc = g++
include = ../Include

.PHONY : clean all

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %.o, $(src))

app : $(obj)
	$(cc) -o app -I $(include) $(obj)

%.o : %.cc
	$(cc) -c $< -I $(include) -o $@

clean:
	rm -f *.o
	rm -f app

