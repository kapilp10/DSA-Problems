class Solution {
public:
    int maxSum(vector<int>& nums, int k) 
    {
        long mod=1e9+7;
        long long res=0;
        vector<int> count(32,0);
        for(int& num : nums)
        {
            for(int i=0;i<32;i++)
            {
                if(num &(1<<i))
                {
                    count[i]++;
                }
            }
        }
        while(k--)
        {
            long long curr=0;
            for(int b=0;b<32;b++)
            {
                if(count[b]>0)
                {
                    count[b]--;
                    curr=(curr | (1<<b)); 
                }
            }
            res=(res+(curr*curr)%mod)%mod;
        }
        return res;
    }
};