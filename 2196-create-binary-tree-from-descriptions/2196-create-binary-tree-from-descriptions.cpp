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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        unordered_set<int> childNodes;
        unordered_map<int,TreeNode*> m;
        for(auto a: descriptions)
        {
            TreeNode* parent = NULL;
            TreeNode* child = NULL;
            
            if(m.find(a[0])==m.end())
                m[a[0]] = new TreeNode(a[0]);

            if(m.find(a[1])==m.end())
                m[a[1]] = new TreeNode(a[1]);
        
            parent = m[a[0]];
            child = m[a[1]];
            
            if(a[2]==0)
                parent->right = child;
            else
                parent->left = child;
    
             childNodes.insert(a[1]);
        }
        
        for(auto a:m)
        {
            if(childNodes.find(a.first)==childNodes.end())
                return a.second;
        }
        return NULL;
            
    }
};