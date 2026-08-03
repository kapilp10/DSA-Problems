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
    // void inorder(TreeNode* res,TreeNode* root)
    // {
    //     if(!root) return;
    //     inorder(res,root->left);
    //     res->right=new TreeNode(root->val);
    //     res->left=NULL;
    //     res=res->right;
    //     inorder(res,root->right);

    // }

    // TreeNode* increasingBST(TreeNode* root) 
    // {
    //     TreeNode* res = new TreeNode();
    //     TreeNode* temp;
    //     temp=res;
    //     inorder(res,root);
    //     return temp->right;  
    // }

        TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};