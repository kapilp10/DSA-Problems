class Solution {
public:
vector<vector<string>> res;
bool isPalindrome(string& str) {
        int i = 0, j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++; j--;
        }
        return true;
    }

void backtrack(string& s,int start,vector<string> temp,vector<vector<string>>& res)
{
    if(start==s.size()) 
    {
        res.push_back(temp);
        return;
    }
    for(int end=start+1;end<=s.size();end++)
    {
        string sub=s.substr(start,end-start);
        if(isPalindrome(sub))
        {
            temp.push_back(sub);
            backtrack(s,end,temp,res);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) 
    {
    vector<string> temp;
    backtrack(s,0,temp,res);
    return res;
        
    }
};