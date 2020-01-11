namespace data_structures {
  class binary_search_tree
  {
    private:
      int data;
      binary_search_tree* left;
      binary_search_tree* right;
      void remove(int val, binary_search_tree* prev);
      
    public:
      binary_search_tree() : data(0), left(nullptr), right(nullptr) {};
      ~binary_search_tree();
      void insert(int val);
      void remove(int val);
      bool find(int val);

      friend std::ostream& operator<<(std::ostream& o, const binary_search_tree& list);
  };

  std::ostream& operator<<(std::ostream& o, const binary_search_tree& list);
}
