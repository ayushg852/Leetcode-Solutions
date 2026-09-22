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
unordered_map<TreeNode*, int> stsize;
    int subtree(TreeNode* root)
    {
        int a=1;
        if(root->left)
        {
            a+=subtree(root->left);
        }
        if(root->right)
        {
            a+=subtree(root->right);
        }
        return stsize[root]=a;
    }
    int ans;
    void dfs(TreeNode* root, int k)
    {
        int a=root->left?stsize[root->left]:0;
        if(a>=k)
        dfs(root->left,k);
        else if(k-a==1)
        ans=root->val;
        else
        dfs(root->right,k-a-1);
    }
    int kthSmallest(TreeNode* root, int k) {
        subtree(root);
        dfs(root,k);
        return ans;
    }
};