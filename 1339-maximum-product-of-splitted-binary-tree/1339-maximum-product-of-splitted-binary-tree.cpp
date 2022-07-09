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
    int solve(TreeNode* root,long int &maxProd,long int &totalSum)
{
    if(root==NULL)
        return 0;
        
    long int sum = root->val;
    sum+=solve(root->left,maxProd,totalSum);
    sum+=solve(root->right,maxProd,totalSum);
    maxProd = max(maxProd,(totalSum-sum)*sum);
    return sum;
}
    
    int calculateSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lSum = calculateSum(root->left);
        int rSum = calculateSum(root->right);
        return root->val+lSum+rSum;
    }
public:
    int maxProduct(TreeNode* root) 
    {
        long int totalSum = calculateSum(root);
        long int maxProd = INT_MIN;
        solve(root,maxProd,totalSum);
        return maxProd%1000000007;
    }
};