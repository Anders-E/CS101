namespace datastructures {

  class singly_linked_list
  {
    private:
      struct node {
        node(int data) : data(data), next(nullptr) {}
        int data;
        struct node *next;
      };
      node *root;
      int size;
    
    public:
      singly_linked_list();
      singly_linked_list(int arr[], int n);
      ~singly_linked_list();
      int get(int i);
      void insert(int data, int i);
      void append(int data);
      int remove(int i);
      int getSize();
      
      friend std::ostream& operator<<(std::ostream& o, const singly_linked_list& list);
  };

  std::ostream& operator<<(std::ostream& o, const singly_linked_list& list);
}
