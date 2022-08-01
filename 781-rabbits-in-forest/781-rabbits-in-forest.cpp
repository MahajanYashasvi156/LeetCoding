/*
The basic thought is: if answers[i] == anwers[j], we take them as the same color as far as possible.
What does the possible mean? Well, we can see a example:
Condider a anwer sequence [2, 2, 2, 2]. According to the Pigeonhole Principle, we cannot take all of them as the same color since there are at most 3 pigeonhole and 4 pigeons.

The solution is using a freq map to store the freq of each color. Each time a pigeonhole is full when reset corresponding element in color.
*/
class Solution 
{
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int,int> freq;
        
        int ans = 0;
        for(int a : answers)
        {
            freq[a]++;
            if(freq[a]==1)
                ans = ans+a+1;
            if(freq[a]==a+1)
                freq[a] = 0;
        }
        
        return ans;
    }
};