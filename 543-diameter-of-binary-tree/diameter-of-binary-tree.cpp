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
    int  best=INT_MIN;
    int bestH(TreeNode* node)
    {
        if(!node) return 0;
        int l=bestH(node->left);
        int r=bestH(node->right);
        best=max(best,l+r);
        return 1 + max(l,r);

    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        bestH(root);
        return best;
    }
};