# change application name here (executable output name)
TARGET=t

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) 

GTKLIB=`pkg-config --cflags --libs gtk+-3.0` -pipe

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) `pkg-config --cflags --libs gtksourceview-3.0` -ljson-c -export-dynamic

OBJS=main.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o -w
    
clean:
	rm -f *.o $(TARGET)
# CFLAGS += $(shell pkg-config --cflags json-c)
# LDFLAGS += $(shell pkg-config --libs json-c)

