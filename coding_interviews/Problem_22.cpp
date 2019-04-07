//problem 22

bool IsPopOrder(const int *pPush,const int *pPop,int length)
{
	if(pPush==NULL||pPop==NULL||length<1)return false;
	
	const int *pPushNext=pPush;
	const int *pPopNext=pPop;
	
	stack<int>StackData;
	
	while(pPopNext-pPop<length)//对弹出序列每一个都判断
	{
		
		while( StackData.empty()||StackData.top()!=*pPopNext)
		{
			if(pPushNext-pPush==length)break;
			StackData.push(*pPushNext);
			
			pPushNext++;
		}
		
		if(StackData.top() != *pPopNext)return false;
		
		
		StackData.pop();
		
		pPopNext++;
	}
	
	
	
	return true;
	
}
