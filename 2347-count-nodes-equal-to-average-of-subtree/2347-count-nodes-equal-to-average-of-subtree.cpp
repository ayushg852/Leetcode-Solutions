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
    int ans=0;
    pair<int,int> func(TreeNode *root)
    {
        if(root==NULL)
        return {0,0};
        int sum=root->val;
        int no=1;
        auto [a,b]=func(root->left);
        sum+=a;
        no+=b;
        auto [c,d]=func(root->right);
        sum+=c;
        no+=d;
        if(sum/no == root->val)
        ans++;
        return {sum,no};
    }
    int averageOfSubtree(TreeNode* root) {
        func(root);
        return ans;
    }
};