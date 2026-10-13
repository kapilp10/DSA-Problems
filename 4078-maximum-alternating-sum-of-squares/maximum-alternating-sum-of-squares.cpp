class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        vector<int> sqr;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int s = nums[i]*nums[i];
            sqr.push_back(s);
        }
        sort(sqr.begin(), sqr.end());
        int mid = n/2;
        long long lsum=0;
        long long rsum=0;
        for(int i=0;i<mid;i++)
        {
            lsum += sqr[i];
        }
        for(int j=mid;j<n;j++)
        {
            rsum += sqr[j];
        }

        return rsum-lsum;
    }
};