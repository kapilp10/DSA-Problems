class Solution {
public:
    void backtrack(int idx, vector<int>& nums, set<vector<int>>& s, vector<int>& temp)
    {
        if (idx == nums.size())
        {
            if (temp.size() > 1) s.insert(temp);
            return;
        }
        if (temp.empty() || nums[idx] >= temp.back())
        {
            temp.push_back(nums[idx]);
            backtrack(idx + 1, nums, s, temp);
            temp.pop_back();
        }
        backtrack(idx + 1, nums, s, temp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<int> temp;
        set<vector<int>> s;
        backtrack(0, nums, s, temp);
        return vector<vector<int>>(s.begin(), s.end());
    }
};