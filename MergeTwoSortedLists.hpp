//non-recursive method to merge two sorted lists

ListNode* merge(ListNode*list1,ListNode*list2)
{
	if(list1==NULL)
	{
		return list2;
	}
	if(list2==NULL){
		return list1
	}

	ListNode*result=NULL;
	ListNode*tmp=NULL;//temp  ListNode pointer
	ListNode*pHead=NULL;//final return ListNode pointer


	ListNode*right=list2;
	ListNode*left=list1;
	int value=right->value >= left->value ? left->value:right->value;
	pHead=new ListNode(value);
	result=pHead;

	while(left->pNext!=NULL&&right->pNext!=NULL)
	{
		if(left->value<=right->value)
		{
			tmp=new ListNode(left->value);
			result->pNext=tmp;
			result=result->pNext;
			left=left->pNext;

		}else{
			tmp=new ListNode(right->value);
			result->pNext=tmp;
			result=result->pNext;
			right=right->pNext;
		}

	}

	while(left->pNext!=NULL)
	{
		tmp=new ListNode(left->value);
		result->pNext=tmp;
		result=result->pNext;
		left=left->pNext;
	}

	while(right->pNext!=NULL)
	{
		tmp=new ListNode(right->value);
			result->pNext=tmp;
			result=result->pNext;
			right=right->pNext;

	}


return pHead;
}