//原地归并排序


//快速交换两个整数的值
void swap(int&a,int&b)
{
	a=a^b;
	b=a^b;
	a=a^b;

}

//逆序排列数组
void reverse(int *arr,int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		swap(arr[i],arr[j]);
		i++;
		j--;
	}

}

//将i至mid-1  和  mid至j-1 的部分对调
void exchange(int *arr,int n,int i)
{
	reverse(arr,i);
	reverse(arr+i,n-i);
	reverse(arr,n);
}

//原地合并
void Merge(int * arr,int low,int mid,int high)
{
	int i=low;int j=mid;int k=high;

	while(i<j&&j<=k)
	{
		int step=0;
		while(i<j&&arr[i]<arr[j])i++;

		while(j<=k&&arr[i]>arr[j])j++;step++;

		//交换两部分内容
		exchange(arr+i,j-i,j-i-step);
		
		i+=step;
	}
}


//原地排序总入口
void MergeSort_Inplace(int *arr,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		MergeSort(arr,l,mid);
		MergeSort(arr,mid+1,r);
		Merge(arr,l,mid+1,r);
	}
}