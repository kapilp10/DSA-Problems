class Solution {
public:
    void backtrack(int start, vector<vector<int>>& res,vector<int>& nums)
    {
        if(start==nums.size())
        {
            vector<int> temp;
            for(int i=0;i<nums.size();i++)
            {
                temp.push_back(nums[i]);
            }
            res.push_back(temp);
            return;
        }

        for(int i=start;i<nums.size();i++)
        {
            swap(nums[i],nums[start]);
            backtrack(start+1,res,nums);
            swap(nums[i],nums[start]);
          
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        backtrack(0,res,nums);
        return res;
    }
};