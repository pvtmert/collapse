
#ifndef _COLLAPSE_H_
#define _COLLAPSE_H_

#ifndef BLOCKSIZE
#define BLOCKSIZE 16
//#warning using default blocksize!
#endif

#ifndef SUFFIX
#define SUFFIX ".cop"
#endif

#include <stdint.h>
#include <stdbool.h>

#include "list.h"

typedef struct Chunk {
	char block[BLOCKSIZE];
	list_t *locs;
} chunk_t;

typedef struct Data {
	size_t size;
	void *data;
} data_t;

chunk_t* compress(FILE*);
data_t* decompress(FILE*);
size_t action(FILE*, FILE*, bool);
size_t chunk_size(list_t*);

#endif
