class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int asc_c = 0;
        int desc_c = 0;

        for(int i=1;i<n;i++)
        {
            asc_c+=(nums[i] == (nums[i-1]+1)%n);
            desc_c+=(nums[i-1] == (nums[i]+1)%n);
        }

        if(asc_c == n-1  && nums[0] == 0)
        {
            return 0;
        }
        if(asc_c == n-1)
        {
            int lr=n-nums[0];
            int rr=nums.back()+3;
            return min(lr,rr);
        } 

        if(desc_c == n-1)
        {
            int lr = n-nums.back()+1;
            int rr = (nums[0]+1)%n+1;
            return min(lr,rr);
        }  
        return -1;     
    }
};