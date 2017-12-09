CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g -I.
DEPS = utils/utils.h
DEF_ARGS = 

%.o: %.c %.h $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)
	
%: %.o
	 ./$< $(DEF_ARGS)
