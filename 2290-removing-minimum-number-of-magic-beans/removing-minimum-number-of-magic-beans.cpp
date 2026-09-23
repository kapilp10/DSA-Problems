class Solution {
public:
    long long minimumRemoval(vector<int>& beans) 
    {
        long n=beans.size();
        sort(beans.begin(),beans.end());
        long long total=accumulate(beans.begin(),beans.end(),0LL);
        long long minLen=LLONG_MAX;
        for(int i=0;i<beans.size();i++)
        {
            minLen=min(minLen,total-n*beans[i]);
            n--;
        }
        return minLen;
        
    }
};