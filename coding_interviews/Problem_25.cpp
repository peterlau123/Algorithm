//problem 25,find all possible paths in addition to paths from root to leaves
//by liuxin,2017.9.2
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode * m_pLeft;
	BinaryTreeNode * m_pRight;
};

void FindPath(stack<BinaryTreeNode*>&st,int vsum,int expectedSum,vector<vector<int>>&vPath)
{
	if(st.empty())return;

	if(vsum==expectedSum)//till this node,accumulated sum equals expectedSum
	{
		vector<int>v;
		v.push_back(pRoot->m_nValue);
		vPath.push_back(v);
	}

	BinaryTreeNode* tmp=st.top();

	bool flag=(tmp->m_pLeft==NULL)&&(tmp->m_pRight==NULL);
	if(flag)//if current node's left and right child's pointer is null
	{		//pop the current node
		st.pop();
		return ;
	}
	else
	{
		if (tmp->m_pLeft!=NULL)//traverse the left node first
		{
			st.push(tmp->m_pLeft);
			//vsum+=tmp->m_nValue;
			FindPath(st,vsum+tmp->m_nValue,expectedSum,vPath)
		}

		if (tmp->m_pRight!=NULL)
		{
			st.push(tmp->m_pRight);
			//vsum+=tmp->m_nValue;
			FindPath(st,vsum+tmp->m_nValue,expectedSum,vPath)
		}

		st.pop();//pop it after traversing its children
	}



}

void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
	if(pRoot==NULL)return ;

	vector<vector<int>>vPath;//store node values

	stack<BinaryTreeNode*>st;
	st.push(pRoot);

	int vsum=pRoot->m_nValue;
	if(pRoot->m_pLeft!=NULL)
	{
		st.push(pRoot->m_pLeft);
		FindPath(st,vsum+pRoot->m_pLeft->m_nValue,expectedSum,vPath);	
	}

	if(pRoot->m_pRight!=NULL)
	{
		st.push(pRoot->m_pRight);
		FindPath(st,vsum+pRoot->m_pRight->m_nValue,expectedSum,vPath);	
	}
	
	//finally,print th tracklets	
}