class Solution {
public:
    string frequencySort(string s) 
    {
        string res;
        unordered_map<char,int> freq;
         for(auto i : s)
        {
            freq[i]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq; 
        for(auto [i,j] : freq)
        {
            pq.push({j,i});
        }
        while(!pq.empty())
        {
            for(int i=0;i<pq.top().first;i++)
            {
                res.push_back(pq.top().second);
            }
            pq.pop();
        }
       return res;
    }
};