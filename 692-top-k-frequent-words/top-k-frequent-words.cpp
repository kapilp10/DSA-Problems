class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        struct compare{
            bool operator()(const pair<int,string> &a,const pair<int,string> &b)
            {
                if(a.first!=b.first)
                {
                    return a.first>b.first;
                }
                return a.second<b.second;
            }
        };
        unordered_map<string,int> freq;
        vector<string> res;
        for(auto& w: words)
        {
            freq[w]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> min_heap;
        for(auto& [w,f] : freq)
        {
            min_heap.push({f,w});
            if(min_heap.size()>k) min_heap.pop();
        }
        while(!min_heap.empty())
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};