#include <iostream>

#include "binary_search_tree.h"

namespace data_structures {

  binary_search_tree::~binary_search_tree()
  {

  }

  void binary_search_tree::insert(int val)
  {
    if (!data) {
      data = val;
    } else if (val < data) {
      if (!left) {
        left = new binary_search_tree();
      }
      left->insert(val);
    } else {
      if (!right) {
        right = new binary_search_tree();
      }
      right->insert(val);
    }
  }
  
  void binary_search_tree::remove(int val)
  {
    if (data)
      this->remove(val, nullptr);
  }

  void binary_search_tree::remove(int val, binary_search_tree* prev)
  {

  }
  
  bool binary_search_tree::find(int val)
  {
    if (!data)
      return false;
    if (data == val)
      return true;
    if (val < data && left)
      return left->find(val);
    if (right)
      return right->find(val);
    return false;
  }

  std::ostream& operator<<(std::ostream& o, const binary_search_tree& tree)
  {
    o << '[' << tree.data;
    if (tree.left)
      o << ", " << *tree.left;
    if (tree.right)
      o << ", " << *tree.right;
    o << ']';

    return o;
  }

}
