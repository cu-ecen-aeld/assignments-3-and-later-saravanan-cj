
ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)gcc
else
	CC = gcc
endif

all: writer set_permissions

writer:
	$(CC) -c writer.c -o writer.o
	$(CC) writer.o -o writer

set_permissions:
	chmod 777 writer 
clean:
	rm *.o

