class Solution {
public:
void backtrack(int idx, int target, vector<int> &a,vector<int> &t,vector<vector<int>>& res){
    if(idx==a.size()){
        if(target==0) {
            res.push_back(t);
        }
        return;
    }

    if(a[idx]<=target){
        t.push_back(a[idx]);
        backtrack(idx,target-a[idx],a,t,res);
        t.pop_back();
    }
    backtrack(idx+1,target,a,t,res); 
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(0,target,candidates,temp,res);
        return res;
    }
};