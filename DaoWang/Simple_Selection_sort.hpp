void SelectSort(ElemType A[],int n)
{
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])min=j;
		}

		if(min!=j)swap(A[min],A[j]);
	}




}