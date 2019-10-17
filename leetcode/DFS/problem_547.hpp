class solution
{

   void Depth_first(const int ind,const vector<vector<int>>&Adj,vector<int>&prNode)
   {
		   vector<int>tmp=Adj[ind];

		   for(int i=0;i<tmp.size();i++)//查询其相邻节点
		   {
				if(prNode[tmp[i]]==0)
				{
				 
				 prNode[tmp[i]]=1;
				 Depth_first(tmp[i],Adj,prNode);

				// prNode[tmp[i]]=1;
				}
						
		   }
		   
   }


   int findCircleNum(vector<vector<int>>& M)
   {
		  int rn=M.size();
		  if(rn==0)return 0;
		  int cn=M[0].size();
		  if(cn==0)return 0;
		  
		  //construct Adj matrix
		  vector<vector<int>>Adj;
          for(int i=0;i<rn;i++)
		  {
		     vector<int> tmp;
		     for(int j=0;j<cn;j++)
		     {
				if(M[i][j]==1&&j!=i)
				{
				tmp.push_back(j);
				}

		     }
			 Adj.push_back(tmp);
		  }


		  //初始化每个节点为0，未被访问状态
		  vector<int>peNode(rn);
		  for(int i=0;i<rn;i++)
		  {
				  peNode.push_back(0);
		  }
		  
		
		int count=0;//number of friend circle
         for(int i=0;i<rn;i++)
		 {
			if(peNode[i]==0)
		    {		
				
				peNode[i]=1;
				Depth_first(i,Adj,peNode);
				//peNode[i]=1;
				count++;
		    }
			 
		 }		


     return count;
   }		
		
};
