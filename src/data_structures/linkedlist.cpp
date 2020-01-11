#include <iostream>

#include "linkedlist.h"

namespace data_structures {

  singly_linked_list::singly_linked_list(int arr[], int n) : root(nullptr), len(n)
  {
    if (len < 1) {
      len = 0;
      return;
    }

    root = new node(arr[0]);
    node *current = root;
    for (int i = 2; i < len; i++) {
      current->next = new node(arr[i]);
      current = current->next;
    }
  }

  singly_linked_list::~singly_linked_list()
  {
    node *current = root;
    while (current) {
      node *tmp = current;
      current = current->next;
      delete tmp;
    }
  }

  int singly_linked_list::get(int n)
  {
    check_bounds(n);

    node *current = root;
    for (int i = 0; i < n - 1; i++)
      current = current->next;

    return current->data;
  }

  void singly_linked_list::insert(int data, int n)
  {
    check_bounds(n);

    node *current = root;
    for (int i = 0; i < n - 1; i++)
      current = current->next;
    
    node *tmp = current->next;
    current->next = new node(data);
    current->next->next = tmp;
    len++;
  }

  void singly_linked_list::append(int data)
  {
    node *new_node = new node(data);
    if (!root) {
      root = new_node;
    } else {
      node *current = root;
      while (current->next)
        current = current->next;
      current->next = new_node;
    }
    len++;
  }

  int singly_linked_list::remove(int n)
  {
    check_bounds(n);

    node* current = root;

    for (int i = 0; i < n - 1; i++)
      current = current->next;
    
    node *tmp = current->next;
    current->next = current->next->next;
    delete tmp;
    len--;

    return current->data;
  }

  int singly_linked_list::length()
  {
    return len;
  }

  void singly_linked_list::check_bounds(int n) {
    if (n < 0 || n >= len)
      throw std::out_of_range("singly_linked_list : index is out of range");
  }

  std::ostream& operator<<(std::ostream& o, const singly_linked_list& list)
  {
    singly_linked_list::node *current = list.root;
    o << '[';
    while (current) {
      o << current->data;
      if (current->next)
        o << ", ";
      current = current->next;
    }
    o << ']';
    return o;
  }

}
