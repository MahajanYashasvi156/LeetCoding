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


void solve(TreeNode* A,string num,string &ans)
{
    cout<<A->val;
    char c = A->val + 'a';
    num = num + c;
    if(A->left==NULL and A->right==NULL)
    {
        reverse(num.begin(),num.end());
        if(ans =="")
            ans = num;
        else
            ans = min(ans,num);
        return;
    }
        
    if(A->left)
        solve(A->left,num,ans);
    if(A->right)
        solve(A->right,num,ans);
}

class Solution 
{
public:
    string smallestFromLeaf(TreeNode* A) 
    {
        string ans ="";
        solve(A,"",ans);
        return ans;
    }
};