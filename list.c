
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "list.h"

void list_set(list_t *list, node_t *nodes, size_t sizes[LIST_DIR_SIZE]) {
	for(int i=0; i<LIST_DIR_SIZE && sizes; i++) {
		list->sizes[i] = sizes[i];
		continue;
	}
	list->nodes = nodes;
	return;
}

void list_fix_sizes(list_t *list) {
	if(!list || !list->nodes) {
		return;
	}
	node_t *prev = list->nodes;
	node_t *next = list->nodes;
	list->sizes[LIST_DIR_BWD] = -1;
	list->sizes[LIST_DIR_FWD] = -1;
	while(prev || next) {
		if(prev) {
			list->sizes[LIST_DIR_BWD] += 1;
			prev = prev->prev;
		}
		if(next) {
			list->sizes[LIST_DIR_FWD] += 1;
			next = next->next;
		}
		continue;
	}
	return;
}

list_t* list_make(node_t *nodes) {
	list_t *list = malloc(sizeof(list_t));
	list_set(list, nodes, (size_t[2]) {0, 0});
	return list;
}


size_t list_size(list_t* list) {
	return 1 + list->sizes[LIST_DIR_FWD] + list->sizes[LIST_DIR_BWD];
}

void list_insert(list_t *dst, list_t *src, bool prev) {
	node_insert(dst->nodes, src->nodes, prev);
	return list_fix_sizes(dst);
}

void list_add(list_t *dst, list_t *src) {
	node_add(dst->nodes, src->nodes);
	return;
}

void list_each(list_t *list, node_callback_loop_f callback) {
	return node_each(list->nodes, callback);
}

list_t* list_remove(list_t *list, bool prev) {
	return list_make(node_remove(list->nodes, prev));
}
