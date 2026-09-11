class Solution {
public:
    int totalNumbers(vector<int>& digits) 
    {
        unordered_set<int> nums;
        int n=digits.size();
        for(int h=0;h<n;h++)
        {
            if(digits[h]==0) continue;;
            for(int t=0;t<n;t++)
            {
                if(h==t) continue;
                for(int u=0;u<digits.size();u++)
                {
                    if(u==t || u==h) continue;
                    if(digits[u]%2!=0) continue;
                    int num=digits[h]*100+digits[t]*10+digits[u];
                    nums.insert(num);
                }
            }
        }
        return nums.size();
    }
};