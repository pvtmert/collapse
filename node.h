
#ifndef _NODE_H_
#define _NODE_H_

typedef struct Node {
	struct Node *prev;
	struct Node *next;
	void *data;
} node_t;

typedef void (node_callback_loop_f) (void*);

node_t* node_make(void*);
node_t* node_head(node_t*);
node_t* node_tail(node_t*);
void node_insert(node_t*, node_t*, bool);
void node_add(node_t*, node_t*);
node_t* node_nth(node_t*, size_t, bool);
size_t node_pos(node_t*, node_t*, bool);
void node_each(node_t*, node_callback_loop_f);
node_t* node_remove(node_t*, bool);

#endif
