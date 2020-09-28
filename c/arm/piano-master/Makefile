vpath %.c = source/
vpath %.h = inlcude/

SRCPATH = ./source

SRC = $(wildcard source/*.c)
OBJ = $(SRC:%.c=%.o)
OBJ := $(filter-out source/piano.o, $(OBJ))

CROSS = arm-none-linux-gnueabi


CC = $(CROSS)-gcc

CPPFLAGS += -I ./include
#CPPFLAGS += -DDEBUG

LDFLAGS  += -L ./lib
LDFLAGS  += -lpthread
LDFLAGS  += -lbmp
#LDFLAGS  += -Wl,-rpath=./lib

all:clean piano

piano:piano.c $(OBJ)
	$(MAKE) -C $(SRCPATH)
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS)

$(OBJ):%.o:%.c
	$(CC) $< -o $@ $(CPPFLAGS) $(LDFLAGS) -c

clean:
	$(RM) $(OBJ) piano .*.sw?

distclean:clean
	$(RM) ./lib/libbmp*
