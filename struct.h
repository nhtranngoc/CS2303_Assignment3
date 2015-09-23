#ifndef STRUCT_H
#define STRUCT_H

#include "mystring.h"
#include <string.h>
#include <stdlib.h>


typedef struct{
	char* type;
	int height;
	int rank;
} alien;

alien* generate_alien(char* type, int height, int rank);
void print_alien(alien* a);
alien* generate_random_alien();
char* generate_random_string(size_t length);
int generate_random_int(int min, int max);
alien** generate_alien_count(size_t count);
void print_alien_count(alien** arr, size_t count);
alien** alien_shallow_copy(alien** src, size_t count);
void alien_free(alien** a, size_t count);
alien** alien_deep_copy(alien** a, size_t count);

#endif