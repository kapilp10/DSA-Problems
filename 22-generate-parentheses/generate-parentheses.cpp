class Solution {
public:
    void backtrack(int open, int close, string s,vector<string>& res,int n)
    {  
        if(s.length()==n*2)
        {
            res.push_back(s);
            return;
        }
        if(open<n)
        {
            backtrack(open+1,close,s+"(",res,n);
        }
            
        if(close<open)
        {
            backtrack(open,close+1,s+")",res,n);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string s="";
        backtrack(0,0,s,res,n);
        return res;
    }
};