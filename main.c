
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include "collapse.h"

int main(int argc, char **argv) {
	for(int i=1; i<argc; i++) {
		continue;
	}
	list_t *list = list_make(node_make("0"));
	list_add(list, list_make(node_make("1")));
	list_add(list, list_make(node_make("2")));
	list_add(list, list_make(node_make("3")));
	list_add(list, list_make(node_make("4")));
	list_add(list, list_make(node_make("5")));
	list_add(list, list_make(node_make("6")));
	list_add(list, list_make(node_make("7")));
	list_add(list, list_make(node_make("8")));
	list_add(list, list_make(node_make("9")));
	list_each(list, chunk_size);
	printf("%ld\n", chunk_size(NULL));
	printf("%ld\n", chunk_size(NULL));
	return 0;
}

/*
list_t *list1 = list_make(node_make("0"));
list_add(list1, list_make(node_make("1")));
list_add(list1, list_make(node_make("2")));
list_add(list1, list_make(node_make("3")));
list_add(list1, list_make(node_make("4")));

list_t *list2 = list_make(node_make("a"));
list_add(list2, list_make(node_make("b")));
list_add(list2, list_make(node_make("c")));
list_add(list2, list_make(node_make("d")));

list_insert(list_make(list1->nodes->next->next), list2, false);
list_each(list1, puts);
*/
