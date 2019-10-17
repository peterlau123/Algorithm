//快排的应用
//奇数在偶数前面
//method 1
void reorderOddEven(int *pData,unsigned int length)
{
	if(!pData||length==0)return ;

	int low=0;
	int high=length-1;

	while(low<high)
	{
		while(low<high&&pData[high]&0x1==0)high--;
		while(low<high&&pData[low]&0x1==1)low++
		int temp=pData[high];
		pData[high]=pData[low];
		pData[low]=temp;
	}


}

//method 2
//使用函数指针，当需要修改判别规则时，直接在外函数内修改