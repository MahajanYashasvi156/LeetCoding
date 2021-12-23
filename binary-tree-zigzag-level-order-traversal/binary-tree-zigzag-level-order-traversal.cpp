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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> levelOrderTraversal;
        
        if(root==NULL) 
            return levelOrderTraversal;
        
        TreeNode* curr;
        
        queue<TreeNode*> q;
        vector<int>levelres;
        int flag=0;
        q.push(root);
        while(!q.empty())
        {
            int nodesAtCurrLevel=q.size();
            while(nodesAtCurrLevel--)
            {
                curr=q.front();
                q.pop();
                levelres.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);  
            }
            if(flag==1)
            {
              reverse(levelres.begin(),levelres.end());
              flag=0;
            } 
            else
                flag=1;
            
            levelOrderTraversal.push_back(levelres);
            levelres.clear();
        }
        return levelOrderTraversal;
    }
};