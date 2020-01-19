#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list {
	struct node *root;
	int length;
};

struct linked_list *linked_list_new();
void linked_list_free(struct linked_list *list);
int linked_list_get(struct linked_list *list, int n);
void linked_list_set(struct linked_list *list, int data, int n);
void linked_list_insert(struct linked_list *list, int data, int n);
void linked_list_append(struct linked_list *list, int data);
void linked_list_remove(struct linked_list *list, int n);
void linked_list_print(struct linked_list *list);

#endif // !LINKED_LIST_H
