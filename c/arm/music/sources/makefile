all : app

cc = arm-linux-gcc
include = ../Include

.PHONY : clean all

src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

app : $(obj)
	$(cc) -o app -I $(include) $(obj)

%.o : %.c
	$(cc) -c $< -I $(include) -o $@ -std=c99

clean:
	rm -f *.o
	rm -f app

