class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long currSum=0;
        long total=0;
        int minL=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            total +=nums[i];
        }
        int rem = total % p;
        if(rem==0) return 0;

        unordered_map<int,int> prefSum;
        prefSum[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            int cRem=currSum%p;
            int nRem=(cRem-rem+p)%p;
            if(prefSum.find(nRem)!=prefSum.end())
            {
                minL=min(minL,i-prefSum[nRem]);
            }
            prefSum[cRem]=i;
        }

        return  minL==nums.size()?-1:minL;
    }

};