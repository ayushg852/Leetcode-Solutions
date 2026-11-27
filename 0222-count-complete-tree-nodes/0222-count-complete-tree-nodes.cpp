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
    int ans;
    void func(TreeNode* node)
    {
        ans++;
        if(node->left==NULL&&node->right==NULL)
        return;
        int h1=0;
        TreeNode* temp=node->left;
        while(temp)
        {
            h1++;
            temp=temp->left;
        }
        int h2=0;
        temp=node->right;
        while(temp)
        {
            h2++;
            temp=temp->left;
        }
        if(h1==h2)
        {
            ans+=(1<<h1)-1;
            func(node->right);
        }
        else
        {
            ans+=(1<<h2)-1;
            func(node->left);
        }
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        func(root);
        return ans;
    }
};