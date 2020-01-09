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
      int len;
      void check_bounds(int n);
    
    public:
      singly_linked_list() : root(nullptr), len(0) {};
      singly_linked_list(int arr[], int n);
      ~singly_linked_list();
      int get(int n);
      void insert(int data, int n);
      void append(int data);
      int remove(int n);
      int length();
      
      friend std::ostream& operator<<(std::ostream& o, const singly_linked_list& list);
  };

  std::ostream& operator<<(std::ostream& o, const singly_linked_list& list);
}
