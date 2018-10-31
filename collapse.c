
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>

#include "collapse.h"

chunk_t* chunk_make(list_t *list) {
	chunk_t *chunk = malloc(sizeof(chunk_t));
	return chunk;
}

size_t chunk_blocks(chunk_t *chunk) {
	if(!chunk) {
		return 0;
	}
	return list_size(chunk->locs)-1;
}

size_t chunk_size(list_t *chunk) {
	static size_t result;
	if(!chunk) {
		return (result | (result=0));
	} else {
		result += 1;
	}
	return result;
}

chunk_t* compress(FILE *fp) {
	return NULL;
}

data_t* decompress(FILE *fp) {
	return NULL;
}

size_t action(FILE *out, FILE *in, bool state) {
	return 0;
}
