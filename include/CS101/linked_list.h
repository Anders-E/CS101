#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct CS101_linked_list {
	struct node *root;
	int length;
} CS101_linked_list;

CS101_linked_list *linked_list_new();
void linked_list_free(CS101_linked_list *list);
int linked_list_get(CS101_linked_list *list, int n);
void linked_list_set(CS101_linked_list *list, int data, int n);
void linked_list_insert(CS101_linked_list *list, int data, int n);
void linked_list_append(CS101_linked_list *list, int data);
void linked_list_remove(CS101_linked_list *list, int n);
void linked_list_print(CS101_linked_list *list);

#endif // !LINKED_LIST_H
