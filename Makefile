CC = clang
CFLAGS = -Wall -g

# default target
all: test_fibonacci

# building object file for fibonacci module
fibonacci.o: fibonacci.c fibonacci.h
	$(CC) $(CFLAGS) -c fibonacci.c

# building object file for test driver
test_fibonacci.o: test_fibonacci.c fibonacci.h
	$(CC) $(CFLAGS) -c test_fibonacci.c

# linking everything to create  executable
test_fibonacci: fibonacci.o test_fibonacci.o
	$(CC) $(CFLAGS) fibonacci.o test_fibonacci.o -o test_fibonacci

# providing a 'test' target
test: test_fibonacci
	./test_fibonacci

# clean up
clean:
	rm -f *.o test_fibonacci
