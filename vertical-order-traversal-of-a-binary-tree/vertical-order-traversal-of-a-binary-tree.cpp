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
/*
Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/

TC - O(NlogN)
SC - O(N)
Aux Space - O(N)

Approach - Maintain a map of vector of pairs.

Recursively call each node's left and right child. 
Row index of both left and right child is incremented by 1.
Column index of left will be parent col - 1 and right will be parent col + 1.
The nodes on the same column index will be on the same vertical line.

Root node col(horizontal distance) = 0, row(level) = 0
Vertical order traversal wants to print the nodes column wise and then row wise.
So we will maintain a ordered map.
Key - Column index.
Value - Pair of row index and node value.

Now we will form map, then we will iterate the map
While iterating we will sort each map entry based on row index 
So now we will have map ordered on cols, and every value of key ordered on rows
So this will be our col wise then row wise vertical order traversal.
*/


class Solution 
{
    private:
        void dfs(TreeNode* root,map<int,vector<pair<int,int>>>&mp,int row,int col)
        {
            if(root==NULL)
                return;
            mp[col].push_back({row,root->val});
            dfs(root->left,mp,row+1,col-1);
            dfs(root->right,mp,row+1,col+1);
        }
    public:
        
        vector<vector<int>> verticalTraversal(TreeNode* root) 
        {
            map<int,vector<pair<int,int>>> mp;
            vector<vector<int>> result;
            vector<int> temp;
            
            dfs(root,mp,0,0);
        
            for(auto a:mp)
            {
                sort(a.second.begin(),a.second.end());// on the basis of row
                for(auto ele:a.second)
                    temp.push_back(ele.second);
                result.push_back(temp);
                temp.clear();
            }
            return result;
        }
};