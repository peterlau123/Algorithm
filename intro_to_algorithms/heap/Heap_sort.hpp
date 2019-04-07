/*
 *chapter 6
 * A is an array
   i is the index
   heapSize is the size of A
*/

heapsort(A) {
  build_max_heap(A);
  while (1 < A.heapSize) {
    exchange A[1] with A[A.heapSize];
    A.heapSize -= 1;
    max_heapify(A, 1);
  }
}
