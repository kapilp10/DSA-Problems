/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pathsum(TreeNode* root, int targetSum, vector<vector<int>>& res,vector<int>& temp)
    {
        if(!root)
        {
            return;
        }
        temp.push_back(root->val);
        if(!root->left && !root->right && targetSum==root->val)
        {
            res.push_back(temp);
        }
        else
        {
            pathsum(root->left,targetSum-root->val,res,temp);
            pathsum(root->right,targetSum-root->val,res,temp);
        }
        temp.pop_back();
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> temp;
        vector<vector<int>> res;
        pathsum(root,targetSum,res,temp);
        return res;

    }
};