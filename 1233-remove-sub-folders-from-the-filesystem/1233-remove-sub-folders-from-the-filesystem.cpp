class Node
{
    public:
        unordered_map<string,Node*>links;
        bool flag = false;
};

class Trie 
{
    Node* root ;
    public:
        Trie()
        {
            root = new Node();
        }
        
        void insert(string s)
        {
            Node* curr = root;
            
            for(int i = 1;i<s.size();i++)
            {
                string name = "";
                
                while(i<s.size() and s[i]!='/')
                {
                    name = name + s[i];
                    i++;
                }
                if(curr->links.find(name)==curr->links.end())
                {
                    curr->links[name] = new Node();
                }
                curr = curr->links[name];
            }
            curr->flag = true;
        }
    
        bool search(string s)
        {
            Node* curr = root;
            
            for(int i = 1;i<s.size();i++)
            {
                if(curr->flag==true)
                    return false;
                
                string name = "";
                while(i<s.size() and s[i]!='/')
                {
                     name = name + s[i];
                     i++;
                }
                curr = curr->links[name];
            }
            return true;
        }
};
class Solution
{
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        Trie trie;
        
        vector<string> result;
        
        for(string s : folder)
        {
            trie.insert(s);
        }
        
        for(string s : folder)
        {
            if(trie.search(s))
            {
                result.push_back(s);
            }
        }
        return result;
    }
};