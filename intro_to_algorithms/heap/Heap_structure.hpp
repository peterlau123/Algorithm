/*
 *chapter 6
 *prolem number:6.2-2,6.2-5,6.2-6
 *
 * A is an array
   i is the index
   heapSize is the size of A
*/

//@brief：max-heapify
// prerequisite:i的左右孩子已经是最大子堆的根结点

int A[4] = {4, 3, 2, 1};
int parent[] = {-1, 4, 4, 3};
int heapSize = 4;

// pseudo-code,recursive
void max_heapify(int A[], int i)
{
	// l and r are indexes
	int l = Left(i);
	int r = Right(i);
	int largest;
	if (l <= heapSize && A[l] < A[i])
	{
		largest = i;
	}
	else
	{
		largest = l;
	}

	if (r <= heapSize && A[r] < A[largest])
	{
	}
	else
	{
		largest = r;
	}

	if (largest != i)
	{
		// exchange A[i] with A[largest];
		max_heapify(A, largest);
	}
}

// pseudo-code,loop
void max_heapify_2(int A[], int i)
{
	int larger = i;
	while (larger <= heapSize)
	{
		int l = Left(i);
		int r = Right(i);

		if (l <= heapSize and A[l] < A[i])
		{
			larger = i;
		}
		else
			larger = l;

		if (r <= heapSize and A[r] < A[larger])
		{
		}
		else
			larger = r;

		if (larger != i)
		{
			// exchange A[i] with A[larger];
			larger = i
		}
	}
}

// rust impl

//@brief:build-max-heap

// pseudo-code
build_max_heap(A)
{
	heapSize = A.length;
	for (i in floor(heapSize / 2)... 1)
	{
		max - heapify(A, i);
	}
}
