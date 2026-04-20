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
   void binTreePath(TreeNode* node, vector<string>& res, string t)
   {
    t=t+to_string(node->val);
    if(node->left)
    {
       binTreePath(node->left,res, t+"->");
    }
    if(node->right) 
    {
        binTreePath(node->right,res, t+"->");
    }
    if(!node->left && !node->right) 
    {
        res.push_back(t);
    }
    
   }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        binTreePath(root,res,"");
        return res;
        
    }
};