class Solution {
public:
    int backtrack(const string& s, int i, int j) 
    {
        int ans = 0, bal = 0;
        for (int k = i; k < j; ++k) 
        {
            bal += (s[k] == '(' ? 1 : -1);
            if (bal == 0) 
            {
                if (k - i == 1) 
                {
                    ans++;
                } else 
                {
                    ans += 2 * backtrack(s, i + 1, k);
                }
                i = k + 1;
            }
        }
        return ans;
    }
    int scoreOfParentheses(string s) 
    {
        return backtrack(s, 0, s.length());
    }
};