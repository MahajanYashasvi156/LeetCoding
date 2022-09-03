class Node
{
    public:
    
    Node* childrens[26]={NULL};
    int end = 0;
};

class Trie
{ 
    public:
    Node* root  = new Node();
        void insert(string s)
        {
            Node* curr = root;
            
            for(char c : s)
            {
                if(curr->childrens[c-'a']==NULL)
                {
                    curr->childrens[c-'a'] = new Node();
                   
                }
                 curr = curr->childrens[c-'a'];
            }
            curr->end++;
        }
    
        int dfs(Node* root,vector<vector<int>>&pos,int index)
        {
            int result = 0;
            
            for(int i = 0;i<26;i++)
            {
                if(root->childrens[i])
                {
                    int newIndex = upper_bound(pos[i].begin(),pos[i].end(),index) - pos[i].begin();
                    
                    if(newIndex==pos[i].size())
                        continue;
                    result = result + dfs(root->childrens[i],pos,pos[i][newIndex]);
                }
            }
            return result + root->end;
        }
};
class Solution 
{
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        Trie trie;
        
        for(string str:words)
            trie.insert(str);
        
        vector<vector<int>> pos(26);
        
        for(int i = 0;i<s.size();i++)
        {
            pos[s[i]-'a'].push_back(i);
        }
        
        return trie.dfs(trie.root,pos,-1);
    }
};



/*
class Solution 
{
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map<char,vector<string>> m;
        
        //Which words are waiting for which words is stored here.
        for(string str: words)
            m[str[0]].push_back(str);
        
        for(int i = 0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                vector<string> currCharWaiting = m[s[i]];
                
                m.erase(s[i]);
                
                for(string str : currCharWaiting)
                {
                    if(str.size()==1)
                        m['$'].push_back("1");
                    else
                        m[str[1]].push_back(str.substr(1));
                }
            }
        }
        return m['$'].size();
    }
};
*/