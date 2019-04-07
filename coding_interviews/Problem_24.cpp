//problem 24 
//by liuxin on 2017.9.2

bool VerifySequenceOfBST(int sequence[],int length)
{
	//exception check
	if(sequence==NULL||length<=0)return false;
	if(sequence!=NULL&&length==1)return true;

	//now we begin checking
	int root=sequence[length-1];

	int *ls=NULL;
	int *rs=NULL;

	//================
	int split=0;
	for(int i=0;i<length;i++)
	{
		if(sequence[i]>root)
		{
			split=i;
			break;
		}
	}

	ls=(split==0)?NULL:sequence;
	
	for (int i = split; i < length; ++i)
	{
		if(sequence[i]<root)
		{
			return false;
		}
	}
	
	rs=sequence+split;

	return VerifySequenceOfBST(rs,length-split)&&VerifySequenceOfBST(ls,split);

}