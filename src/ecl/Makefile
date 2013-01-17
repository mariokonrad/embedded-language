.PHONY: all clean

CC=gcc
CFLAGS+=

all : simple

simple : simple.o
	$(CC) -o $@ $^ -L$(LIB_DIR) -lecl

clean :
	$(RM) *.o
	$(RM) simple

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INC_DIR_ECL)

