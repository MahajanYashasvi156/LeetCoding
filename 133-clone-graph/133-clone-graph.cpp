/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/



class Solution 
{
    Node* dfs(Node* src, map<Node*,Node*> &m)
    {
        Node *newSrc = new Node(src->val);
        m[src]=newSrc;
     
        for( auto dst : src->neighbors)
        {
            if(m.find(dst) == m.end())
                newSrc->neighbors.push_back(dfs(dst,m)); 
            else 
                newSrc->neighbors.push_back(m[dst]);
        }
        return newSrc;
    }
public:
    Node* cloneGraph(Node* node)
    {
        if(node == NULL)
            return node;
        map<Node*,Node*> m;
        return dfs(node,m);
    }
};