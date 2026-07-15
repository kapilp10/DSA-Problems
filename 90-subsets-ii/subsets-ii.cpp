class Solution {
public:
    vector<vector<int>> res;
    void back_track(vector<int>& nums,int start, vector<int>& temp,vector<vector<int>>& res)
    {
        res.push_back(temp);
        for(int i=start;i<nums.size();i++)
        {
            if(i>start && nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        back_track(nums,i+1,temp,res);
        temp.pop_back();
        }
    }
// void backtrack(vector<int>& nums, int start,
//                vector<int>& cur, vector<vector<int>>& res) {
//     res.push_back(cur);
//     for (int i = start; i < nums.size(); i++) {
//         if (i > start && nums[i] == nums[i-1]) continue;   // skip duplicate
//         cur.push_back(nums[i]);
//         backtrack(nums, i+1, cur, res);
//         cur.pop_back();
//     }
// }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        back_track(nums,0,temp,res);
        return res;
    }
};