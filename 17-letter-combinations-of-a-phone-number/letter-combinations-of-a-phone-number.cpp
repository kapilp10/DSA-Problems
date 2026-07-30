class Solution {
public:
void helper(int ind, string digits,string s,vector<string>& ans, string combo[])
{
    if(ind==digits.size())
    {
        ans.push_back(s);
        return;
    }

    int digit = digits[ind]-'0';

    for(int i=0;i<combo[digit].size();i++)
    {
        helper(ind+1,digits,s+combo[digit][i],ans,combo);
    }
}
    vector<string> letterCombinations(string digits) {
        string combo[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s="";
        helper(0,digits,s,ans,combo);
        return ans;
        
    }
};