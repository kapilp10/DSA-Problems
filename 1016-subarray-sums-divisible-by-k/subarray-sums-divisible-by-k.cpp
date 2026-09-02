class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0]=1;
        int prefixSum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            if(rem<0)
            {
                rem=(rem+k)%k;
            }
            if(prefixSumCount.find(rem)!=prefixSumCount.end())
            {
                count+=prefixSumCount[rem];
            }
            prefixSumCount[rem]++;
            
        }
        return count;
        
    }
};