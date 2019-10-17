// by liuxin,17.4.20
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        
        if(root==NULL)return result;
        
        queue<TreeNode*>Nodes;//遍历每层节点使用queue
        Nodes.push(root);
        
        //====================
        bool flag=true;//true代表从左向右排，false代表从右向左排
        while(!Nodes.empty())
        {
            vector<int>temp;
            int len=Nodes.size();
            
            for(int i=0;i<len;i++)//依次取出每个节点的值
            {
                TreeNode *tmp=Nodes.front();
                temp.push_back(tmp->val);
                
                if(tmp->left!=NULL){Nodes.push(tmp->left);}
                if(tmp->right!=NULL){Nodes.push(tmp->right);}
                
                //========
                Nodes.pop();
            }

            //根据flag确定元素摆放顺序
            if(flag)
            {
             result.push_back(temp);
             flag=false;
             
            }else{
                
            reverse(temp.begin(),temp.end());//反转vector
            
            result.push_back(temp); 
            flag=true;
            
            }
 
        }
        
        
        
    return result;   
    }
    
    
};