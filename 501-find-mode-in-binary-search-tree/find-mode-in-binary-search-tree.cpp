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
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> freq;
        vector<int> res;
        dfs(root,freq);
        int mx=0;
        for(auto &i : freq)
        {
            mx=max(mx,i.second);
        }

        for(auto &k : freq)
        {
            if(k.second==mx)
            res.push_back(k.first);
        }
        return res;
    }
    void dfs(TreeNode* node,unordered_map<int,int>& freq)
    {
        if(!node)
        {
            return;
        }
        freq[node->val]++;
        dfs(node->left,freq);
        dfs(node->right,freq);
    }
};