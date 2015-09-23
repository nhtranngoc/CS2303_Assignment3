#include "struct.h"

/**
 * @brief Generate an aliens from parameters.
 * @param type Type of alien.
 * @param height Height of alien.
 * @param rank Rank of invading aliens.
 * @return Pointer to newly built alien.
 */
alien* generate_alien(char* type, int height, int rank){
	alien *a = (alien *)malloc(sizeof(alien));
	a->type = mystrndup(type, mystrlen(type));
	a->height = height;
	a->rank = rank;
	return a;
}

/**
 * @brief Generate a random alien with random type, height and rank.
 * @return Randomized alien.
 */
alien* generate_random_alien(){
	alien* a = (alien *)malloc(sizeof(alien));
	char* type = generate_random_string(8);
	a->type = mystrndup(type, mystrlen(type));
	a->height = generate_random_int(1, 16);
	a->rank = generate_random_int(1, 10);
	return a;
}

/**
 * @brief Print out an alien.
 * @param a The alien to print out.
 */
void print_alien(alien* a){
	printf("Alien Type %s:\n\tHeight: %d\n\tRank: %d\n", a->type, a->height, a->rank);
}

/**
 * @brief Generate a random string of length.
 * @param length Max length of string.
 * @return Randomized string.
 */
char* generate_random_string(size_t length){
	char* str = (char *)malloc(length+1);
	size_t i;
	for (i=0; i< length; i++){
		*(str+i) = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
	}
	*(str + length) = '\0';
	return str;
}

/**
 * @brief Generate a random number in range.
 * @param min Min randomized value .
 * @param max Max randomized value.
 * @return Randomized number in range (min, max).
 */
int generate_random_int(int min, int max){
	double scaled = (double)rand()/RAND_MAX;
	return (max - min +1)*scaled + min;
}

/** 
 * @brief Make an array of random aliens with a given size count.
 * @param n The number of elements in array.
 * @return A pointer to randomized array of aliens.
 */
alien** generate_alien_count(size_t count){
    alien** a = (alien **)malloc(count * sizeof(alien*));
    size_t i;
    for (i = 0; i < count; i++){
        a[i] = generate_random_alien();
    }
    return a;
}

/**
 * @brief Print an array of structs.
 * @param arr Array to print out.
 * @param count Number of elements in array.
 */
void print_alien_count(alien** arr, size_t count){
    int i;
    for (i = 0; i < count; i++){
        print_alien(arr[i]);
    }
}

/**
 * @brief Shallow copy an array of pointers to struct.
 * @param src Source array to copy from.
 * @param count Length of the array.
 * @return Shallow copy of the array.
 */
alien** alien_shallow_copy(alien** src, size_t count){
    alien** a = (alien **)malloc(count * sizeof(alien**));
    size_t i;
    for (i = 0; i < count; i++){
        a[i] = src[i];
    }
    return a;
}

/**
 * @brief Free an array of pointers to alien.
 * @param a Array to free.
 * @param count Length of the array.
 */
void alien_free(alien** a, size_t count){
    size_t i;
    for (i = 0; i < count; i++){
        free(a[i]);
        a[i] = NULL;
    }
}

/**
 * @brief Deep copy an array of pointers of struct.
 * @param a Source array to copy from
 * @param count Length of the array
 * @return Deep copy of the array
 */
alien** alien_deep_copy(alien** a, size_t count){
    alien** a_cpy = (alien**)malloc(count * sizeof(alien)); 
    size_t i;
    for (i = 0; i < count; i++){
        a_cpy[i] = generate_alien(a[i]->type, a[i]->height, a[i]->rank);
    }
    return a_cpy;
}
