CS2303 Assignment 3

by nhtranngoc

#Building the programs:
In the directory, type in: 
make

To clean up: type: 
make clean

to make the documentation and put them under /public_html, type: 
make docs


#Programs:

##ctest

This program demonstrates the use of arrays, character strings, dynamically allocated memory and pointers.

To use: type:
./ctest

Expected output: (Randomized names may varies)

Pointers: a1 = 0x7ffef47e3d70, a2 = 0x7ffef47e3e60, a3 = 0x7ffef47e3d50
          p1 = 0x40152c p2 = 0x7ff9b88ee1c8
a1 = Hi
a2 = Hello
a3 = Hello, also
Concatenating a2 to the end of a1
a1 = HiHello
Concatenating a2 to the end of a1, with copy_limit = 13
a1 = HiHelloHello
Concatenating a3 to the end of a1, with copy_limit = 8
a1 = HiHelloHelloHello, a
Before dup, pointer a2 = 0x7ffef47e3e60, contents = Hello
Duplicated string: 
Pointer p2 = 0x17c4010, contents = Hello
a4 too long= The brown fox jumps �
a4 = The brown fox
p3 with a word limit of 5 = The br
Alien Type Kif:
	Height: 7
	Rank: 9
Alien Type Kal-El:
	Height: 9
	Rank: 2
Alien Type NWLRBBMQ:
	Height: 5
	Rank: 6
Alien Type CDARZOWK:
	Height: 3
	Rank: 7
--------------PRINTING ARRAY OF ALIENS--------------
--------------PUT ON YOUR TINFOIL HAT--------------
Alien 5: 
Alien Type HIDDQSCD:
	Height: 16
	Rank: 3
Alien Type JMOWFRXS:
	Height: 5
	Rank: 8
Alien Type BLDBEFSA:
	Height: 2
	Rank: 10
Alien Type BYNECDYG:
	Height: 8
	Rank: 1
Alien Type XPKLOREL:
	Height: 9
	Rank: 7
Shallow copy of Alien 5: 
Alien Type HIDDQSCD:
	Height: 16
	Rank: 3
Alien Type JMOWFRXS:
	Height: 5
	Rank: 8
Alien Type BLDBEFSA:
	Height: 2
	Rank: 10
Alien Type BYNECDYG:
	Height: 8
	Rank: 1
Alien Type XPKLOREL:
	Height: 9
	Rank: 7
Deep copy of Alien 5: 
Alien Type HIDDQSCD:
	Height: 16
	Rank: 3
Alien Type JMOWFRXS:
	Height: 5
	Rank: 8
Alien Type BLDBEFSA:
	Height: 2
	Rank: 10
Alien Type BYNECDYG:
	Height: 8
	Rank: 1
Alien Type XPKLOREL:
	Height: 9
	Rank: 7
