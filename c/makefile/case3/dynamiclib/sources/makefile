all : app

cc = g++
include = ../Include

.PHONY : clean all

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %.o, $(src))

app : $(obj)
	$(cc) -shared -o libdynamicapp.so $(obj)

%.o : %.cc
	$(cc) -fPIC -c $< -I $(include) -o $@

clean:
	rm -f *.o
	rm -f app

