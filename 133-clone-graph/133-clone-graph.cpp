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

/*
Link - https://leetcode.com/problems/clone-graph/

TC - O(V+E) //DFS
SC - O(V)
ASC - O(V)

Appraoch - 
Perform DFS with some modification.
1. Instead of visited vector, maintain visited map which indicates following -
    a) Whether the input node is created and explored or not.
    b) Mapping of old address of the node with its cloned address.
    
2. Same as DFS, set visited in the beginning of the call.
3. a)If the neighbour is in the map i.e. neighbour is created and explored then just add new address of the neighbour to the neighbout list.
   b) Else Call DFS on the neighbour.
   
*/
class Solution 
{
    Node* dfs(Node* node,map<Node*,Node*> &visited)
    {
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
        if(node==NULL)
            return NULL;
        map<Node*,Node*> visited;
        return dfs(node,visited); 
    }
};