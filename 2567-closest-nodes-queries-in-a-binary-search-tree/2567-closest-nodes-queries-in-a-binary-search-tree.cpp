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
    vector<int> v;
    void func(TreeNode* root)
    {
        if(root==nullptr)
        return;
        func(root->left);
        v.push_back(root->val);
        func(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        func(root);
        vector<vector<int>> ans;
        for(auto &x:queries)
        {
            auto it=lower_bound(v.begin(),v.end(),x);
            if(it!=v.end()&&(*it)==x)
            {
                ans.push_back({x,x});
                continue;
            }
            int mi=-1;
            int ma=-1;
            if(it!=v.end())
            ma=*it;
            if(it!=v.begin())
            mi=*(prev(it));
            ans.push_back({mi,ma});
        }
        return ans;
    }
};