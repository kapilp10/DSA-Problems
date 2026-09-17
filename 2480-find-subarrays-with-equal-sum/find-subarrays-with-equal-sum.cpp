class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        int sum;
        unordered_map<int , bool> mp;
        for(int i=0;i<n-1;i++)
        {
            sum=nums[i]+nums[i+1];
            if(mp.contains(sum)) return true;
            else mp[sum]=true;
        }
        return false;
        
    }
};