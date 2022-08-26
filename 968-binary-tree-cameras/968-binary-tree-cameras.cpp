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
    int ans = 0;
    
    string solve(TreeNode* root)
    {
        if(root==NULL)
            return "HAS_COVERED";
        
        if(root->left==NULL and root->right==NULL)
            return "PLEASE_COVER"; 
        
        string leftPlaced = solve(root->left);
        string rightPlaced = solve(root->right);
        
        if(leftPlaced == "PLEASE_COVER" || rightPlaced == "PLEASE_COVER") 
        {
            ans ++;
            return "HAS_CAMERA"; 
        }
        
        if(leftPlaced == "HAS_CAMERA" || rightPlaced == "HAS_CAMERA")
            return "HAS_COVERED";
        
        return "PLEASE_COVER";
    }
public:
    int minCameraCover(TreeNode* root)
    {
        if(root->left==NULL and root->right==NULL)
            return 1;
        
        return solve(root)=="PLEASE_COVER" ? ans+1: ans;
    }
};