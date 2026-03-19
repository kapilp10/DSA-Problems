class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int mn=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(mn<prices[i])
            {
                mx=mx+prices[i]-mn;
            }
            mn=prices[i];
        }
        return mx;
    }
};