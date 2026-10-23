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
    int sumNumbers(TreeNode* root) 
    {
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int totalSum=0;
        while(!q.empty())
        {
            TreeNode* curr = q.front().first;
            int k=q.front().second;
            k=k*10+curr->val;
            q.pop();
            if(!curr->left  && !curr->right)
            {
                totalSum += k;
            }

            if(curr->left)
            {
                q.push({curr->left,k});
            }
            if(curr->right)
            {
                q.push({curr->right,k});
            }

        }
        return totalSum;
        
    }
};