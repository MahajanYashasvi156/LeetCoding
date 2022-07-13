class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        wordList.push_back(beginWord);
   
        unordered_map<string,vector<string>> graph;

        for(int i = 1;i<wordList.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                int diffrent = 0;
                for(int k = 0;k<wordList[i].size();k++)
                {
                    if(wordList[i][k]!=wordList[j][k])
                        diffrent++;
                }
                if(diffrent == 1)
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<string> q;
        unordered_map<string,bool>visited;

        q.push(beginWord);
        visited[beginWord]=true;
        int steps = 1;

        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                string currstr = q.front();
                q.pop();
                if(currstr == endWord)
                    return steps;

                for(auto next : graph[currstr])
                {
                    if(visited.find(next)==visited.end())
                    {
                        visited[next]=true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};