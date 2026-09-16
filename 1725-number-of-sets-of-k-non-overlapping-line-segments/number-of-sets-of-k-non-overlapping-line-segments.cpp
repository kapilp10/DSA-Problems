class Solution {
public:
    int numberOfSets(int n, int K) 
    {
        int M=1e9+7;
        vector<vector<int>> dp(K + 1, vector<int>(n + 1, 0));
        for(int i=0;i<=n-1;i++)
        {
            dp[0][i]=1;
        }
        for(int k=1;k<=K;k++)
        {
            vector<int> prevSum(n+1,0);
            for(int x=n-1;x>=0;x--)
            {
                prevSum[x]=(prevSum[x+1]+dp[k-1][x])%M;
            }

            for(int i=n-1;i>=0;i--)
            {
                long long take = prevSum[i+1];
                long long skip= dp[k][i+1]%M;
                dp[k][i]=(take + skip) % M;
            }
        }
        return dp[K][0];
    }
};