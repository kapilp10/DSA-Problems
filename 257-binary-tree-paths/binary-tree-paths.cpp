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
void dfs(TreeNode* node,vector<string>& res, string t)
{
    t=t+to_string(node->val);
    if(node->left)
    {
        dfs(node->left,res,t+"->");
    }
    if(node->right)
    {
        dfs(node->right,res,t+"->");
    }

    if(!node->left && !node->right)
    {
        res.push_back(t);
    }
}
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        dfs(root,res,"");
        return res;
        
    }
};