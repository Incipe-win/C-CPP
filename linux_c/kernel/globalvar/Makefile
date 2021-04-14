PWD = $(shell pwd)
WARN = -Wall -Wstrict-prototypes -Wno-trigraphs -Wmissing-prototypes
INCLUDE = -I/usr/src/linux-headers-5.4.0-31-generic/include

TEMP = -isystem /lib/modules/`uname -r`/build/include

CFLAGS = -O2 -DMODULE -D__KERNEL__ ${WARN} ${INCLUDE}
CC = /usr/bin/gcc

OBJS = ${patsubst %.c, %.o, ${wildcard *.c}}

all : ${OBJS}

.PHONY : clean

clean:
	rm -rf *.o
