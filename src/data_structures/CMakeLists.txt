# Linked List
add_library(linked_list STATIC linked_list.c)
target_compile_features (linked_list PRIVATE c_std_11)
target_include_directories (linked_list PUBLIC "${CS101_INCLUDE_DIR}")

# Heap
add_library(heap STATIC heap.c)
target_compile_features(heap PRIVATE c_std_11)
target_include_directories(heap PUBLIC "${CS101_INCLUDE_DIR}")

# Stack
add_library(stack STATIC stack.c)
target_compile_features(stack PRIVATE c_std_11)
target_include_directories(stack PUBLIC "${CS101_INCLUDE_DIR}")

# Queue
add_library(queue STATIC queue.c)
target_compile_features(queue PRIVATE c_std_11)
target_include_directories(queue PUBLIC "${CS101_INCLUDE_DIR}")
