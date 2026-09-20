class Solution {
public:
    int reverseDegree(string s) 
    {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int revVal=26-(s[i]-'a');
            int idx=i+1;
            sum+=revVal*idx;
        }
        return sum;
    }
};