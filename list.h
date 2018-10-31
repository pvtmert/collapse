
#ifndef _LIST_H_
#define _LIST_H_

#include "node.h"

typedef enum ListDirection {
	LIST_DIR_FWD,
	LIST_DIR_BWD,
	LIST_DIR_SIZE,
} list_dir_t;

typedef struct List {
	struct Node *nodes;
	size_t sizes[LIST_DIR_SIZE];
} list_t;

void list_fix_sizes(list_t*);
list_t* list_make(node_t*);
size_t list_size(list_t*);
void list_insert(list_t*, list_t *, bool);
void list_add(list_t*, list_t*);
void list_each(list_t*, node_callback_loop_f);
list_t* list_remove(list_t*, bool);

#endif
