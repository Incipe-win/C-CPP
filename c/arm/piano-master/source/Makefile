CROSS = arm-none-linux-gnueabi
CC = $(CROSS)-gcc
AR = $(CROSS)-ar

CFLAGS = -shared -fPIC

all:libbmp.so libts.so
	mv $^ ../lib

libbmp.so:bmp.o
	$(CC) $(CFLAGS) -o $@ $^

libts.so:ts.o
	$(CC) $(CFLAGS) -o $@ $^
