class Node
{
    public:
    
        Node* links[26];
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
            for(int i = 0;i<s.size();i++)
            {
               if(curr->links[s[i]-'a']==NULL)
                   curr->links[s[i]-'a'] = new Node();
                curr = curr->links[s[i]-'a'];
            }
            curr->flag = true;
        }
    
        void completeSuggestion(Node* curr,string s,vector<string>&ans)
        {
            if(curr->flag==true)
                ans.push_back(s);
            
            for(char c = 'a';c<='z';c++)
            {
                if(curr->links[c-'a']!=NULL and ans.size()<3)
                    completeSuggestion(curr->links[c-'a'],s+c,ans);
            }
        }
        vector<string> search(string s)
        {
            vector<string> ans;
            
            Node* curr = root; 
            
            for(int i = 0;i<s.size();i++)
            {
                if(curr->links[s[i]-'a']==NULL)
                    return ans;
                curr = curr->links[s[i]-'a'];
            }
            completeSuggestion(curr,s,ans);
            return ans;
            
        }
        
};
class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        Trie trie;
        
        for(string s:products)
            trie.insert(s);
        
        vector<vector<string>> result;
        string s = "";
        for(char c: searchWord)
        {
            s = s+c;
            result.push_back(trie.search(s));
        }
        return result;    
    }
};