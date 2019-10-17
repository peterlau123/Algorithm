//反转链表
struct ListNode
{
	int m_Value;
	ListNode* m_pNext;
}

//
ListNode* ReverseList(ListNode*pHead)
{
	if(pHead==NULL)return NULL;

	if(pHead->m_pNext==NULL)return pHead;

	if(pHead->m_pNext->m_pNext==NULL)
	{
		ListNode*pFirst=pHead;
		pFirst->m_pNext=NULL;

		pHead=pHead->m_pNext;

		pHead=->m=_pNext=pFirst;

		return pHead;
	}

	ListHead *pMiddle=pHead->m_pNext;
	ListNode*pAhead=pmiddle->m_pNext;
	while(pAhead->m_pNext!=NULL)
	{



	}

}