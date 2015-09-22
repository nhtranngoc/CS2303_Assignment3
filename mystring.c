/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/**
 * @brief Returns a pointer to a duplicated string of string s, with a limit of n bytes
 * @param s Pointer to string to be copied 
 * @param n Max number of bytes to duplicate
 * @return Pointer to freshly-allocated string containing a duplicate of src
 * or null if no memory is available
 */
char* mystrndup(const char *s, size_t n){
  char* newstr;
  newstr = (char*) malloc(n+1);

  if (newstr == 0) return (char*)0;

  mystrncpy(newstr, s, n);
  if (newstr[(int)n] != '\0') newstr[(int)n] = '\0';
  return newstr;
}

/**
 * @brief Finds the length of the null terminated string.
 * @param s The string to determine length.
 * @return The length of the string.
 */
size_t mystrlen(const char* s){
    const char* nextChar;
    nextChar = s;
    while (*nextChar != '\0'){ //Add to nextChar until hit a Null character.
        ++nextChar;
    }
    return nextChar - s;
}

/**
 * @brief Copy the string to a destination string.
 * @param *dest pointer to destination string.
 * @param *src pointer to source string.
 * @return The destination string.
 */
char* mystrcpy(char *dest, const char *src){
  const char* nextChar;
    nextChar = src;
    while(*nextChar != '\0'){ //Add to nextChar and dest until hit a Null character.
        *dest = *nextChar;
        ++nextChar;
        ++dest;
    }
    *dest = *nextChar;
  return dest;
}

/**
 * @brief Copies the string pointed to by src, including the terminating null byte to the buffer
 * pointed to by dest, at most n bytes. 
 * @param dest String to copy to
 * @param src String to be copied
 * @param n Max number of bytes to cpy
 * @return A pointer to the destination string dest
 */
char* mystrncpy(char* dest, const char* src, size_t n){
  char* nextChar= dest;

  size_t i;
  for (i = 0; i< n; i++){
    *dest = *src;
    if (*src != '\0') ++src;
    ++dest;
  }
  return nextChar;
}

/**
 * @brief Appends the src string to the dest string, overwriting terminating null 
 * byte at the end of dest, and adds a terminating null byte.
 * 
 * @param dest String to be appended.
 * @param src String to append to.
 * 
 * @return A concatenated string from src and dest.
 */
char* mystrcat(char *dest, const char *src){
  char* nextChar= dest;

  while(*dest != '\0') ++dest;
  while(*src != '\0'){
    *dest = *src;
    ++src;
    ++dest;
  }
  *dest= '\0';
  return nextChar;
}

/**
 * @brief ppends the src string to the dest string, overwriting terminating null 
 * byte at the end of dest, and adds a terminating null byte- however, this function uses at
 * most n bytes from src.
 * @param dest String to be appended.
 * @param src String to append to.
 * @param n Max number of bytes to append.
 * @return A concatenated string from src and dest, at a limit of n.
 */
char* mystrncat(char *dest, const char *src, size_t n){
  char* nextChar= dest;

  while(*dest != '\0') ++dest;
  int i;
  for(i=0; i< n; i++){
    *dest = *src;
    ++src;
    ++dest;
  }
  *dest= '\0';
  return nextChar;
}
