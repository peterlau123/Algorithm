//合并两个排序的链表
struct ListNode
{
	int m_Value;
	ListNode* m_pNext;
}


ListNode* Merge(ListNode*pHead1,ListNode*pHead2)
{
	ListNode*result=NULL;
	if(pHead1==NULL)return pHead2;
	if(pHead2==NULL)return pHead1;

	if(pHead1->m_Value>pHead2->m_Value)
	{
		result=pHead2;
	result->m_pNext=Merge(pHead1,pHead2->m_pNext);

	}else{
		result=pHead1;
	result->m_pNext=Merge(pHead1->m_pNext,pHead2);

	}
	

	return result;
}