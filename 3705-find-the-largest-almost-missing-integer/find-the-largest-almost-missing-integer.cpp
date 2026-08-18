class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int> freq;
        for(auto x:nums)
        {
            freq[x]++;
        }
        if(n==k)
        {
           for(int x: nums)
           {
            ans=max(ans,x);
           }
           return ans;
        }
        if(k==1)
        {
            for(auto x: nums)
            {
                if(freq[x]==1)
                {
                    ans=max(ans,x);
                }
            }
            return ans;
        }
        if(freq[nums[0]]==1)
        {
            ans=max(ans,nums[0]);
        }
        if(freq[nums[n-1]]==1)
        {
            ans=max(ans,nums[n-1]);
        }
        return ans;
    }
};