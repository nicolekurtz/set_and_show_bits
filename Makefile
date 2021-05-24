# Nicole Kurtz Make File for setBits and showBits
CC=gcc
# flag all warnings. default optimization level.
CFLAGS=
# set up for use in gdb
DFLAGS=
# For additional libraries, e.g. -lm
PROGS= setBits showBits

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm -f $(PROGS) *.o ~*

