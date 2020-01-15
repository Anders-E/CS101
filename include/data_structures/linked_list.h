#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list {
    int data;
    struct linked_list *next;
};

int linked_list_get(struct linked_list list, int n);
void linked_list_insert(struct linked_list list, int data, int n);
void linked_list_append(struct linked_list list, int data);
int linked_list_remove(struct linked_list list, int n);
int linked_list_length(struct linked_list list);
int linked_list_to_string(struct linked_list list);

#endif // !LINKED_LIST_H
