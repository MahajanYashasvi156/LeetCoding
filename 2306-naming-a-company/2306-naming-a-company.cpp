/*
Approach for this Problem:
Create a vector of 26 unordered_sets, each unordered_set will store strings starting with the same character.
Iterate over each string in the input vector 'ideas'.
Insert each string into the unordered_set corresponding to its first character.
Calculate the number of distinct names by iterating over the unordered_sets twice (once for each pair of sets), comparing the size of the sets before and after adding elements from both sets.
Return the result.

Optimized code - O(n*m) and O(26*n) space
*/
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long disName = 0;
        vector<unordered_set<string>> arr(26);
        for (string s : ideas) 
            arr[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 26; j++) {
                unordered_set<string> set;
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                disName += (arr[i].size() - set.size()) * (arr[j].size() - set.size());
            }
        }
        return disName * 2;
    }
};