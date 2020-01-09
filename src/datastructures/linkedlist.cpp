#include<iostream>

#include "linkedlist.h"

namespace datastructures {

  singly_linked_list::singly_linked_list(int arr[], int n)
  {
    root = nullptr;
    len = n;

    if (len < 1)
      return;

    node* current = root;
    for (int i = 0; i < n; i++) {
      current = new node(arr[i]);
      current = current->next;
    }
  }

  singly_linked_list::~singly_linked_list()
  {
    node *current = root;
    while (current) {
      node* tmp = current;
      current = current->next;
      delete tmp;
    }
  }

  int singly_linked_list::get(int i)
  {
    return 0;
  }

  void singly_linked_list::insert(int data, int i)
  {
  }

  void singly_linked_list::append(int data)
  {
    node *new_node = new node(data);
    if (!root) {
      root = new_node;
    } else {
      node* current = root;
      while (current->next)
        current = current->next;
      current->next = new_node;
    }
    len++;
  }

  int singly_linked_list::remove(int i)
  {
    return 0;
  }

  int singly_linked_list::length()
  {
    return len;
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
