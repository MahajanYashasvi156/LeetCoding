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
    Node* dfs(Node* node,map<Node*,Node*> &visited)
    {
        if(node==NULL)
            return NULL;
        Node * curr = new Node(node->val); 
        visited[node]=curr;
        
        for(Node* n:node->neighbors)
        {
            if(visited.find(n)==visited.end())
                curr->neighbors.push_back(dfs(n,visited));
        
            else
                curr->neighbors.push_back(visited[n]);      
        }
        return curr;
    }
public:
    Node* cloneGraph(Node* node) 
    {
        map<Node*,Node*> visited;
        return dfs(node,visited);
        
    }
};