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
    vector<int> res;
    int count=0;
    int maxCount=0;
    int prev;
    vector<int> findMode(TreeNode* root) 
    {
        inorder(root);
        return res;
    }
    void inorder(TreeNode* node)
    {
        if(!node) return;
        inorder(node->left);
        if(node->val==prev)
        {
            count++;
        }
        else
        {
            count=1;
        }
        if(count>maxCount)
        {
            maxCount=count;
            res.clear();
            res.push_back(node->val);
        }
        else if(count==maxCount)
        {
            res.push_back(node->val);
        }
        prev=node->val;
        inorder(node->right);
    }
};