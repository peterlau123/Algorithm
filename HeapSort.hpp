//
void HeapSort(ElemType A[],int len)
{
	BuildMaxHeap(A,len);

	for(i=len;i>1;i--)
	{
		swap(A[i],A[1]);

		AdjustDown(A,1,i-1);
	}


}