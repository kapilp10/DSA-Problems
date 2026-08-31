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
    bool dfs(TreeNode* root, int sum, int targetSum)
    {
        if(!root)
        {
            return false;
        }
        sum=sum+root->val;
        if(!root->left && !root->right)
        {
            if(targetSum==sum)
            {
                return true;
            }
        }
    bool left=dfs(root->left,sum,targetSum);
    bool right=dfs(root->right,sum,targetSum);
    return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
       return dfs(root,0,targetSum);
    }

};