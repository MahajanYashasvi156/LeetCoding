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
    TreeNode* preorder(vector<int>&nums,int low,int high)
    {
        if(low>=high)
            return NULL;
        int mid = (low+high)/2;
       
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = preorder(nums,low,mid);
        curr->right = preorder(nums,mid+1,high);
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return preorder(nums,0,nums.size());
        
    }
};


