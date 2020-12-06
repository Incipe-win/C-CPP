all : app

cc = gcc
include = "" # ../Include

.PHONY : clean all

src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

app : $(obj)
	$(cc) -o app $(obj)

%.o : %.c
	$(cc) -c $< -o $@ -I $(include) -g

clean:
	rm -f *.o
	rm -f app
