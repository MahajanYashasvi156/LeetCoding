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
public:
    TreeNode* BSTUtility(vector<int>& nums,int low, int high)
    {
        if(high<low)
            return NULL;
        
        int rootIndex=low+(high-low)/2;
        TreeNode* root= new TreeNode(nums[rootIndex]);  
        root->left=BSTUtility(nums,low,rootIndex-1);
        root->right=BSTUtility(nums,rootIndex+1,high);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return BSTUtility(nums,0,nums.size()-1);
    }
};