namespace data_structure {

  class SinglyLinkedList
  {
    private:
      struct Node {
        int data;
        struct Node *next;
      };
      Node root;
      int size;
    
    public:
      SinglyLinkedList();
      ~SinglyLinkedList();
      int get(int i);
      void insert(int data, int i);
      void append(int data);
      int remove(int i);
      int peek(int i);
  };
  
}
