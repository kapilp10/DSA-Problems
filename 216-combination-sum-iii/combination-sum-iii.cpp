class Solution {
public:
    void backtrack(int idx,int target,int k,vector<vector<int>>& res,vector<int>& temp)
    {
        if(temp.size()==k && target==0)
        {
           res.push_back(temp);
           return; 
        }
        for(int i=idx;i<=9;i++)
        {
        temp.push_back(i);
        backtrack(i+1,target-i,k,res,temp);
        temp.pop_back();
        // backtrack(i+1,target-i,k,res,temp);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        // vector<int> nums(10);
        // for(int i=0;i<10;i++)
        // {
        //     nums.push_back(i);
        // }
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(1,n,k,res,temp);
        return res;

    }
};