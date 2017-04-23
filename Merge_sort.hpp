//
void MergeSort(ElemType A[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;

		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}

}

void Merge(ElemType A[],int low,int mid,int high)
{
	ElemType *B=(ElemType*)malloc((n+1)*sizeof(ElemType));

	for(int i=low;low<=high;i++)
		B[i]=A[i];

	int i=low;int j=mid+1;int k=i;
	for(;i<=mid&&j<=high;i++,j++)
	{
		if(B[i]<=B[j])
		{
			A[k]=B[i];k++;
		}else{

			A[k]=B[j];k++;
		}


	}
while(i<=mid)A[k]=B[i];i++,k++;
while(j<=high)A[k]=B[j];j++,k++;


}