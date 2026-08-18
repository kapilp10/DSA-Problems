class Solution {
public:
    int climbS(int n,vector<int>& t)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        if(t[n]!=-1)
        {
            return t[n];
        }
        t[n]=climbS(n-1,t)+climbS(n-2,t);
        return t[n];
    }
    int climbStairs(int n) 
    {
        vector<int> t(n+1,-1);

        return climbS(n,t);
        
    }

};