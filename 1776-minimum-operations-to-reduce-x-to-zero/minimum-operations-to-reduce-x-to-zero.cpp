class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++) total += nums[i];
        int target=total-x;
        if(target<0) return -1;
        if (target==0) return n; 
        int length=-1;
        int left=0;
        int cSum=0;
        for(int right=0;right<n;right++)
        {
            cSum+=nums[right];
            while(left<=right && cSum>target) 
            {
                cSum -= nums[left];
                left++;
            }
            if(cSum==target)
            {
                length=max(length,right-left+1);
            }
        }
        return length==-1? -1 : n-length;
    }
};