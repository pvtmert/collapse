
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "node.h"

#define DEBUG(X) (printf("%s: %16p %16p %16p\n", #X, (X)->prev, (X), (X)->next))

inline void node_set(node_t *node, void *data, node_t *next, node_t *prev) {
	node->prev = prev;
	node->next = next;
	node->data = data;
	return;
}

node_t* node_make(void *data) {
	node_t *node = malloc(sizeof(node_t));
	node_set(node, data, NULL, NULL);
	return node;
}

node_t* node_head(node_t *nodes) {
	while(nodes && nodes->prev) {
		nodes = nodes->prev;
		continue;
	}
	return nodes;
}

node_t* node_tail(node_t *nodes) {
	while(nodes && nodes->next) {
		nodes = nodes->next;
		continue;
	}
	return nodes;
}

void node_insert_prev(node_t *dst, node_t *src) {
	node_head(src)->prev = dst->prev;
	dst->prev = src;
	return;
}

void node_insert_next(node_t *dst, node_t *src) {
	node_t *head = node_head(src);
	node_t *tail = node_tail(src);
	head->prev = dst;
	tail->next = dst->next;
	if(dst->next) {
		dst->next->prev = tail;
	}
	dst->next = head;
	return;
}

void node_insert(node_t *dst, node_t *src, bool prev) {
	return (prev ? node_insert_prev(dst, src) : node_insert_next(dst, src));
}

void node_add(node_t *dst, node_t *src) {
	return node_insert(node_tail(dst), node_head(src), false);
}

node_t* node_nth(node_t *nodes, size_t count, bool prev) {
	while(nodes && count > 0) {
		nodes = prev ? nodes->prev : nodes->next;
		count -= 1;
		continue;
	}
	return nodes;
}

size_t node_pos(node_t *nodes, node_t *node, bool prev) {
	size_t count = 0;
	while(nodes && nodes != node) {
		nodes = prev ? nodes->prev : nodes->next;
		count += 1;
		continue;
	}
	return count;
}

void node_each(node_t *nodes, node_callback_loop_f callback) {
	while(nodes && callback) {
		callback(nodes->data);
		nodes = nodes->next;
		continue;
	}
	return;
}

node_t* node_remove(node_t *node, bool prev) {
	node_t *res = NULL;
	if(prev) {
		res = node->prev;
		node->prev = res->prev;
		if(res->prev) {
			res->prev->next = node;
		}
	} else {
		res = node->next;
		node->next = res->next;
		if(res->next) {
			res->next->prev = node;
		}
	}
	return res;
}
