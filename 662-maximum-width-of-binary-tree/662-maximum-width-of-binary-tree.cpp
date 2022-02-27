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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int maxWidth = INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty())
        {
            int maxIndex = INT_MIN;
            int minIndex = INT_MAX;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                auto n = q.front();
                q.pop();
                int index = n.second;
                TreeNode* curr = n.first;
                maxIndex = max(maxIndex,index);
                minIndex = min(minIndex,index);
                if(curr->left)
                {
                    q.push({curr->left,(long long)2*index+1});
                }
                
                if(curr->right)
                {
                    q.push({curr->right,(long long)2*index+2});
                }
            }
            maxWidth = max(maxWidth,abs(maxIndex - minIndex +1));
        }
        return maxWidth;
    }
};