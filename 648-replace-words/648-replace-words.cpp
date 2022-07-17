class Node
{
    public:
        Node* node[26];
        bool flag = false;
};
class Trie
{
    Node* trie; 
    public:
        Trie()
        {
            trie = new Node();
        }
    
        void insert(string word)
        {
            Node* root = trie;
            
            for(int i = 0;i<word.size();i++)
            {
                if(root->node[word[i]-'a']==NULL)
                    root->node[word[i]-'a'] = new Node();
                root = root->node[word[i]-'a'];
            }
            root->flag = true;
        }
        
        string searchRoot(string succ)
        {
            Node* root = trie;

            string rootWord = "";
            for(int i = 0;i<succ.size();i++)
            {
                if(root->node[succ[i]-'a']==NULL)
                    return succ;
                rootWord = rootWord+succ[i];
                root = root->node[succ[i]-'a'];
                if(root->flag==true)
                    return rootWord;
            }
            return rootWord;
        }
};
class Solution 
{
public:
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        Trie root;
        
        for(string s: dictionary)
            root.insert(s);
        
        string succ = "";
        string ans = "";
        for(char s : sentence)
        {
            if(s==' ')
            {
                ans+=root.searchRoot(succ);
                succ ="";
                ans+=" ";
            }
            else
            {
                succ+=s;
            }
        }
        
        ans+=root.searchRoot(succ);
        return ans;
    }
};