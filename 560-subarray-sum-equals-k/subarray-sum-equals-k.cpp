class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =  nums.size();
        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0]=1;
        int prefixSum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            int remain=prefixSum-k;
            if(prefixSumCount.find(remain)!=prefixSumCount.end())
            {
                count+=prefixSumCount[remain];
            }
            prefixSumCount[prefixSum]++;
        }
        return count;
        
    }
};