class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==1)
        {
            return {nums};
        }

        for(int i=0;i<nums.size();i++)
        {
            int n=nums.front();
            nums.erase(nums.begin());

            vector<vector<int>> perm=permute(nums);
            for(auto i: perm)
            {
                i.push_back(n);
                res.push_back(i);
            }
            nums.push_back(n);
        }
        return res;
        
    }
};