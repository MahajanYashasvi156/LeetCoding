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
class Solution 
{
    void inorderTraversal(TreeNode* root, vector<TreeNode*> &inorder)
    {
        if(root==NULL)
            return ;
        
        inorderTraversal(root->left,inorder);
        inorder.push_back(root);
        inorderTraversal(root->right,inorder);
    }
    TreeNode* constructBST(vector<TreeNode*>&inorder,int low, int high)
    {
        if(low>high)
            return NULL;
        
        int mid = low+(high-low)/2;
        TreeNode* root = inorder[mid];
        
        root->left = constructBST(inorder,low,mid-1);
        root->right = constructBST(inorder,mid+1,high);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<TreeNode*> inorder;
        
        inorderTraversal(root,inorder);
        
        return constructBST(inorder,0,inorder.size()-1);
    }
};