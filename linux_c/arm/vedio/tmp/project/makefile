all : app

cc = arm-linux-gcc

.PHONY : clean all

src = $(wildcard *.c)

app : $(src)
	$(cc) $^ -o $@ -I ./libjpeg -L ./libjpeg -lapi_v4l2_arm -lpthread -ljpeg

clean:
	rm -f app







