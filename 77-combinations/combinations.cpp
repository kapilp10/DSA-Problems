class Solution {
public:
void backtrack(int n, int k, int idx, vector<vector<int>>& res, vector<int>& temp)
{
    if(temp.size()==k)
    {
        res.push_back(temp);
        return;
    }
    for(int i=idx;i<=n;i++)
    {

        temp.push_back(i);
        backtrack(n,k,i+1,res,temp);
        temp.pop_back();
        // backtrack(n,k,i+1,res,temp);
    }

}
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(n,k,1,res,temp);
        return res;
    }
};