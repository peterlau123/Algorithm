//冒泡排序
void BubbleSort(ElemType A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool flag=false;//定义标志变量，避免对已经有序的数组冒泡
		for(int j=n-1;j>i;j--)
		{
			if(A[j-1].key>A[j].key)
			{
				swap(A[j-1],A[j]);
				flag=true;
			}

		if(flag==false)return;
		}


	}


}