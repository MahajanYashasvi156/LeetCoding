/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> traversal;
        
        if(root==NULL)
            return traversal;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int s = q.size();
            while(s--)
            {
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for(Node* child : curr->children)
                {
                    q.push(child);
                }
            }
            traversal.push_back(level);
        }
        return traversal;
    }
};