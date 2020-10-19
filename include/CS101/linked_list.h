#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct CS101_linked_list {
	struct node *root;
	int length;
};

struct CS101_linked_list *linked_list_new();
void linked_list_free(struct CS101_linked_list *list);
int linked_list_get(struct CS101_linked_list *list, int n);
void linked_list_set(struct CS101_linked_list *list, int data, int n);
void linked_list_insert(struct CS101_linked_list *list, int data, int n);
void linked_list_append(struct CS101_linked_list *list, int data);
void linked_list_remove(struct CS101_linked_list *list, int n);
void linked_list_print(struct CS101_linked_list *list);

#endif // !LINKED_LIST_H
