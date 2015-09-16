#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy.

  strcpy(a3, "Hello, also"); // Initialize uinderfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  strcpy(a1, "Hi"); // Initialize character array

  printf("a1 = %s\n", a1);
  printf("a2 = %s\n", a2);
  printf("a3 = %s\n", a3);

  // Be sure there is a terminator character in the last element of the array
  a1[MAX_CHARS] = '\0';

  // Concatenate two character arrays, then print.
  strcat(a1, a2);
  printf("Concatenating a2 to the end of a1\n");
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  printf("Concatenating a2 to the end of a1, with copy_limit = %d\n",copy_limit);
  if (copy_limit > 0) strncat(a1, a2, copy_limit);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  printf("Concatenating a3 to the end of a1, with copy_limit = %d\n",copy_limit);
  if (copy_limit > 0) strncat(a1, a3, copy_limit);
  printf("a1 = %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("Duplicated string: \n");
  printf("Pointer p2 = %p, contents = %s\n", p2, p2);

  return 0;
}
