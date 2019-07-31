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
      SinglyLinkedList(int arr[]);
      ~SinglyLinkedList();      
      int get(int i);
      void insert(int data, int i);
      void append(int data);
      int remove(int i);
      int peek(int i);
  };
  
  SinglyLinkedList::SinglyLinkedList()
  {
    Node root;
  }
  
  SinglyLinkedList::SinglyLinkedList(int arr[]) {
  }

  SinglyLinkedList::~SinglyLinkedList()
  {
  }

  int SinglyLinkedList::get(int i)
  {
    return 0;
  }

  void SinglyLinkedList::insert(int data, int i)
  {
  }

  void SinglyLinkedList::append(int data)
  {
  }

  int SinglyLinkedList::remove(int i)
  {
    return 0;
  }
  
  int SinglyLinkedList::peek(int i)
  {
    return 0;
  }

}
