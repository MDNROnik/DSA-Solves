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
    void fun(TreeNode* root, int level, map<int,int>&mp){
        if(root==NULL){return;}
        mp[level]+=root->val;
        fun(root->left, level+1, mp);
        fun(root->right, level+1, mp);
    }
    int deepestLeavesSum(TreeNode* root) {
        map<int,int>mp;
        fun(root, 0, mp);
        int ans = INT_MIN;
        map<int, int>::reverse_iterator it;
        it=mp.rbegin();
        ans=it->second;
        return ans;
    }
};