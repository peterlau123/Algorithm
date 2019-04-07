//树的镜像
struct BinaryTreeNode
{
	int   m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}

//递归写法
void MirrorRecursively (BinaryTreeNode* pNode)
{
	if(pNode==NULL)return ;
	if(pNode->m_pLeft==NULL&&pNode->m_pRight==NULL)return ;

	BinaryTreeNode *tmp;
	tmp=pNode->m_pLeft;
	pNode->m_pLeft=pNode->m_pRight;
	pNode->m_pRight=tmp;
	
	if(pNode->m_pRight){
	MirrorRecursively(pNode->m_pRight);
	}

	if(pNode->m_pLeft){
	MirrorRecursively(pNode->m_pLeft);
	}
	



}
//非递归写法
void swap(BinaryTreeNode*& pNode1,BinaryTreeNode*& pNode2)
{
	BinaryTreeNode *tmp;
	tmp=pNode1;
	pNode1=pNode2;
	pNode2=tmp;
}

void MirrorRecursively (BinaryTreeNode* pNode)
{
	if(pNode==NULL)return ;
	if(pNode->m_pLeft==NULL&&pNode->m_pRight==NULL)return ;

	queue<BinaryTreeNode*>q;
	q.push_back(pNode);

	while(!q.isEmpty())
	{
		BinaryTreeNode*temp=q.top();
		if(temp!=NULL)
		{
		swap(temp->m_pLeft,temp->m_pRight);
		q.push_back(temp->m_pLeft);
		q.push_back(temp->m_pRight);
		}
		
		q.pop();
	}

}