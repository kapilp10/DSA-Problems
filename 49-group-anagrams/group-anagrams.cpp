class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // vector<string> sortedString = strs;
        // sort(sortedString.begin(),sortedString.end());
        unordered_map<string, vector<string>> freq;
        for(auto i : strs)
        {
            string s=i;
            sort(s.begin(),s.end());
            freq[s].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i : freq)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};