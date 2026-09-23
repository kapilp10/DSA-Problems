class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        long total=accumulate(nums.begin(),nums.end(),0);
        if(total<target) return 0;
        int minLen=n;
        int left=0;
        int prefSum=0;
        for(int right=0;right<n;right++)
        {
            prefSum+=nums[right];
            while(prefSum>=target)
            {
                minLen=min(minLen,right-left+1);
                prefSum-=nums[left++];
            }
            
        }
        return minLen;

    }
};