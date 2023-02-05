//Can be done using rolling hash technique.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
//Stores the Key and frequency of element in Window of size p.size().
        map<char,int> temp;
//Stores the Key and frequency of elements of string p.
        map<char,int> pmap;
//Stores the indexes of anagrams of p in s.
        vector<int> bindexes;
//window size same as p size
        int wsize=p.size(); 
//Store char of p in pmap with its frquency.
        for(char c : p)
            pmap[c]+=1;
        for(int ptr=0;ptr<s.size();ptr++)
        {
            //store the frequecy of each new eleemnt of s.
            temp[s[ptr]]++;
            //Iterating from the last element of the first window. 
            if(ptr>=wsize-1)
            {
                //If the map of current window is same as map of p. Stores the index of first element of the window.
                if(temp==pmap)
                    bindexes.push_back(ptr-wsize+1);
                //Decrease the frequency of removed element of window. If frequency 0 remove from map.
                temp[s[ptr-wsize+1]]--;
                if(temp[s[ptr-wsize+1]]==0)
                    temp.erase(s[ptr-wsize+1]);
            }
            
        }
        return bindexes;
    }
};
/*
class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char,int> pfreq;
        map<char,int> sfreq;
        vector<int> result;
        for(int i=0;i<p.size();i++)
            pfreq[p[i]]++;
        
        int w = p.size();
        for(int i=0;i<s.size();i++)
        {
            sfreq[s[i]]++;
            if(i>=w-1)
            {
                if(pfreq==sfreq)
                    result.push_back(i-w+1);
                sfreq[s[i-w+1]]--;
                if(sfreq[s[i-w+1]]==0)
                    sfreq.erase(s[i-w+1]);
            }
        }
        
        return result;
    }
};
*/