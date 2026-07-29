class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr,vector<int>& temp, vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(temp);
            return;
        }

        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            temp.push_back(arr[i]);
            findCombination(i+1,target-arr[i],arr,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        findCombination(0,target,candidates,temp,res);
        return res;
    }
};