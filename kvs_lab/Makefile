SRCS = main.c
LIBSRCS = open.c close.c put.c get.c skiplist.c
TARG = kvs_static
TARG_DYNAMIC = kvs_dynamic
LIB_SHARED = libkvs.so

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a

all: static dynamic

static: $(TARG)

$(TARG): $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) -static

$(LARS): $(LOBJS)
	ar rs $(LARS) $(LOBJS)

$(LIB_SHARED): $(LOBJS)
	$(CC) -shared -o $(LIB_SHARED) $(LOBJS)

dynamic: $(LIB_SHARED) $(TARG_DYNAMIC)

$(TARG_DYNAMIC): $(OBJS) $(LIB_SHARED)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) -L. -lkvs

%.o: %.c
	$(CC) $(OPTS) -fPIC -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(LIB_SHARED) $(TARG) $(TARG_DYNAMIC)
	
