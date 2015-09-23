all: ctest

ctest: ctest.o mystring.o struct.o
	gcc ctest.o mystring.o struct.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

struct.o: struct.c mystring.h
	gcc -c struct.c

clean: 
	rm -f mystring.o ctest.o struct.o ctest

docs:
	doxygen
	chmod 744 html/*
	cp -rp html/* ~/public_html/cs2303assig3/