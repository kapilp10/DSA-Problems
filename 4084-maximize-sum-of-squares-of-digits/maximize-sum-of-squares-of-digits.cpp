class Solution {
public:
    string maxSumOfSquares(int num, int sum) 
    {
        if(sum>9*num) return "";
        int curr=0;
        string ans;
        while(num-->0)
        {
            curr=min(9,sum);
            sum-=curr;
            ans+=char('0'+curr);
        }
        return ans;
        
    }
};