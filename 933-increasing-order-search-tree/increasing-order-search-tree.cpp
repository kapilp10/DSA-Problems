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
    TreeNode* res;
private:
    void inorder(TreeNode* node)
    {
        if(!node) return;

        inorder(node->left);

        node->left=nullptr;
        res->right = node;
        res=node;


        inorder(node->right);

    }
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode* temp=new TreeNode(0);
        res=temp;
        inorder(root);
        return temp->right;  
    }
};