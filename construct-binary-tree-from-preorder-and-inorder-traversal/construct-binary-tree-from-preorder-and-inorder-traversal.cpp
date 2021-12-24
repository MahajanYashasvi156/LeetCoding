/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> indexInorder;
        
        for(int i=0;i<inorder.size();i++)
            indexInorder[inorder[i]]=i;
        
        TreeNode* root=new TreeNode(preorder[0]);
        
        TreeNode* curr=NULL;
        TreeNode* par=root;
        
        for(int i=1;i<preorder.size();i++)
        {
            curr= root;
            int in = indexInorder[preorder[i]];
            while(curr)
            {
              
                
                if(indexInorder[curr->val]>in)
                {
                    par=curr;
                    curr=curr->left;
                }
                else 
                {
                    par=curr;
                    curr=curr->right;
                }   
                
            }
            if(indexInorder[par->val]>in)
            {
                    par->left=new TreeNode(preorder[i]);
            }
            else 
            {
               par->right=new TreeNode(preorder[i]);
            } 
           
        }
        return root;
    }
};