all : app

cc = arm-linux-gcc
include = ./include
source = ./sources

.PHONY : clean all

src = $(wildcard $(source)/*.c)
obj = $(patsubst %.c, %.o, $(src))

app : $(obj)
	$(cc) -o app -I $(include) $(obj)

%.o : %.c
	$(cc) -c $< -I $(include) -o $@ -std=c99 -Wall

clean:
	rm -f $(source)/*.o
	rm -f app

