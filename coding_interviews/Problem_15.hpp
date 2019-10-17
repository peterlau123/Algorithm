//链表中第K个节点

struct ListNode
{
	int m_Value;
	ListNode* m_pNext;
}

ListNode* FindKthToTail(ListNode*pListHead,unsigned int k)
{
	if(pListHead==NULL||k<=0)return Null;

	ListNode*pAhead=pListHead;
	ListNode*pBehind=pListHead;
	for(int i=0;i<k-1;i++)
	{
		if(pAhead->m_pNext!=NULL){

			pAhead=pAhead->m_pNext;
		}

	}
//===========
	while(pAhead!=NULL)
	{
		pAhead=pAhead->m_pNext;
		pBehind=pBehind->m_pNext;

	}

	return pBehind;
}