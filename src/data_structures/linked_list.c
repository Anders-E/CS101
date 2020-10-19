#include <stdio.h>
#include <stdlib.h>
#include <CS101/linked_list.h>

struct node {
	int data;
	struct node *next;
};

struct node *node_new(int data)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node) {
		new_node->data = data;
		new_node->next = 0;
	}
	return new_node;
}

struct CS101_linked_list *linked_list_new()
{
	struct CS101_linked_list *list = malloc(sizeof(struct CS101_linked_list));
	if (list) {
		list->root = 0;
		list->length = 0;
	}
	return list;
}

void linked_list_free(struct CS101_linked_list *list)
{
	if (list->root) {
		struct node *current = list->root;
		while (current->next) {
			struct node *tmp = current;
			current = current->next;
			free(tmp);
		}
		free(current);
	}
	free(list);
}

int linked_list_get(struct CS101_linked_list *list, int n)
{
	struct node *current = list->root;
	for (int i = 0; i < n; i++)
		current = current->next;
	return current->data;
}

void linked_list_set(struct CS101_linked_list *list, int data, int n)
{
	struct node *current = list->root;
	for (int i = 0; i < n; i++)
		current = current->next;
	current->data = data;
}

void linked_list_insert(struct CS101_linked_list *list, int data, int n)
{
	struct node *new_node = node_new(data);
	if (n == 0) {
		new_node->next = list->root;
		list->root = new_node;
	}
	else {
		struct node *current = list->root;
		for (int i = 0; i < n - 1; i++)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
	list->length++;
}

void linked_list_append(struct CS101_linked_list *list, int data)
{
	struct node *new_node = node_new(data);
	if (!list->root)
		list->root = new_node;
	else {
		struct node *current = list->root;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	list->length++;
}

void linked_list_remove(struct CS101_linked_list *list, int n)
{
	if (n == 0) {
		struct node *tmp = list->root;
		list->root = list->root->next;
		free(tmp);
	}
	else {
		struct node *current = list->root;
		for (int i = 0; i < n - 1; i++)
			current = current->next;
		struct node *tmp = current->next;
		current->next = tmp->next;
		free(tmp);
	}

	if (n >= 0)
		list->length--;
}

void linked_list_print(struct CS101_linked_list *list)
{
	printf("[");
	struct node *current = list->root;
	if (current) {
		printf("%d", current->data);
		while (current->next) {
			current = current->next;
			printf(", %d", current->data);
		}
	}
	printf("]\n");
}

