/*
 *chapter 6
 * A is an array
   i is the index
   heapSize is the size of A
*/
#include <iostream>

#include "Heap_structure.hpp"

//@brief:maximum
int heap_maximum(int A[]) {
  if (heapSize < 1) {
    std::cerr << "queue is too short" << std::endl;
  } else {
    return A[0];
  }
}

//@brief:extract_max
int extract_maximum(int A[]) {
  if (0 < heapSize) {
    int max_element = A[0];
    if (1 < heapSize) {
      A[0] = A[heapSize - 1];
      heapSize -= 1;
      max_heapify(A, 0);
    }

    return max_element;
  }
}

//@brief:increase_key
void heap_increase_ley(int A[], int i, int key) {
  if (i < 0 || heapSize <= i) {
    std::cerr << "wrong i value" << std::endl;
    return;
  }

  if (key <= A[i]) {
    std::cerr << "key value must be greater than A[i]" << std::endl;
    return;
  }
  A[i] = key;
  while (A[parent[i]] < A[i]) {
    // exchange A[parent[i]] with A[i]
    i = parent[i];
    max_heapify(A, i);
  }
}

//@brief:insert a element in the priority queue
void max_heap_insert(int A[], int key) {
  heapSize += 1;
  A[heapSize - 1] = -INT_MAX;
  heap_increase_ley(A, heapSize, key);
}