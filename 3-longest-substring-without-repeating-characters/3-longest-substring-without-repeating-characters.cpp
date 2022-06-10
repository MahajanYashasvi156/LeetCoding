//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_length=0;
        unordered_map<char,int> freq;
        int left=0;
        int curr_length=0;
        for(int right=0;right<s.size();right++)
        {
//Increment left pointer till the duplicate of element at right pointer removed from the window.
           while(freq[s[right]]==1)
           {
                freq[s[left]]--;
                left++;
                curr_length--;
            }
//Include right element in the window.
            freq[s[right]]++;
            curr_length++;
            max_length=max(max_length,curr_length);
        } 
        return max_length;
    }
};