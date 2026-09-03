class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        long long sum=0;
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(prefixSumCount.find(rem)!=prefixSumCount.end())
            {
                if(i-prefixSumCount[rem]>=2)
                {
                    return true;
                }
            }
            else
            {
                prefixSumCount[rem]=i;
            }
        }
        return false;
    }
};