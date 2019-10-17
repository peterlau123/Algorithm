struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
}

void DeleteNode(ListNode**pListHead,ListNode*pToBeDeleted)
{
	if(*pListHead==NULL||pToBeDeleted==NULL)return ;//if(!pListHead==!pToBeDeleted)return;

	ListNode*temp;
	//删除首节点
	if(*pListNode==pToBeDeleted){
	temp=*pListHead;
	*pListHead=(*pListHead)->m_pNext;
	delete temp;
	}
	

	if(pToBeDeleted->m_pNext!=NULL){

	pToBeDeleted->m_nValue=pToBeDeleted->m_pNext->m_nValue;
	temp=pToBeDeleted->m_pNext;
	pToBeDeleted->m_pNext=pToBeDeleted->m_pNext->m_pNext;

	delete temp;
	temp=NULL;

	}else{

		temp=*pListNode;
		while(temp!=pToBeDeleted)
		{
		temp=temp->m_pNext;
		}
		temp=NULL;
		delete pToBeDeleted;

		pToBeDeleted=NULL;
	}
	
//==========

}