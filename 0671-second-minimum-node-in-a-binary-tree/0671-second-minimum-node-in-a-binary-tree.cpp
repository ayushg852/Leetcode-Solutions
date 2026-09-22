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
long ans=1e10;
void dfs(TreeNode* root)
{
    if(root->left)
    {
        if(root->left->val > root->val)
        {
            ans=min(ans,(long)root->left->val);
            dfs(root->right);
        }
        else if(root->right->val > root->val)
        {
            ans=min(ans,(long)root->right->val);
            dfs(root->left);
        }
        else
        {
            dfs(root->left);
            dfs(root->right);
        }
    }
}
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if(ans==1e10)
        return -1;
        return ans;
    }
};