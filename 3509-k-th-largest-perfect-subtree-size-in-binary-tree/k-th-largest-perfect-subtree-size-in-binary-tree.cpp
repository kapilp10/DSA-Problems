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
    void isPerfect(TreeNode* root,int& h,bool& p)
    {
        if(root==NULL) 
        {
            h=0;
            p=true;
            return;
        }
        int lh=0;
        bool lp=false;
        isPerfect(root->left,lh,lp);
        int rh=0;
        bool rp=false;
        isPerfect(root->right,rh,rp);
        if(lp && rp && lh==rh)
        {
            h=rh+1;
            p=true;
        }
        else
        {
            h=0;
            p=false;
        }
    }

    void dfs(vector<int>& res,TreeNode* root)
    {
        if(root==NULL) return;
        dfs(res,root->left);
        dfs(res,root->right);
        int h=0;
        bool p=false;
        isPerfect(root,h,p);
        if(p)
        {
            int size=(1<<h)-1;
            res.push_back(size);
        }
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) 
    {
        vector<int> res;
        dfs(res,root);
        if(res.size()<k) return -1;
        sort(res.rbegin(),res.rend());
        return res[k-1];
    }
};