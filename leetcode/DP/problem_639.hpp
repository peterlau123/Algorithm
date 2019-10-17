/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        TreeNode *result=NULL;
        
        if(d==1)
        {
            result=new TreeNode(v);
            result->left=root;
            return result;
        }
        
        queue<TreeNode *>q;
        q.push(root);
        int cn=1;
        while(cn<d-1) //get all the nodes at depth d-1 using BFS
        {
            TreeNode*tmp=q.front();
            
            if(tmp->left!=NULL) q.push(tmp->left);
            
            if(tmp->right!=NULL) q.push(tmp->right);
            
            q.pop();
            
            cn++;
        }
        
        //begin adding new nodes's values v
        TreeNode * lt=NULL;
        TreeNode * rt=NULL;
        while(!q.empty())
        {
            TreeNode*tmp=q.front();
            
            if(tmp->left!=NULL)lt=tmp->left;
            if(tmp->right!=NULL)rt=tmp->right;
            
            tmp->left=new TreeNode(v);
            tmp->right=new TreeNode(v);
            
            tmp->left->left=lt;
            tmp->right->right=rt;
            
            q.pop();
        }
        
        result=root;
        
        return result;
    }
    
    //================
};