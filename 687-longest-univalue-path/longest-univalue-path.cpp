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
    int best=0;
    int gain(TreeNode* node){
        if(!node) return 0;
        int l = gain(node->left);
        int r = gain(node->right);
        int leftt=0;
        int rightt=0;
        if(node->left && node->left->val==node->val){
            leftt=l+1;
        }
        if(node->right && node->right->val==node->val) {
            rightt=r+1;
        }
        best=max(best,leftt+rightt);
        return max(leftt,rightt);
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        gain(root);
        return best; 
    }
};