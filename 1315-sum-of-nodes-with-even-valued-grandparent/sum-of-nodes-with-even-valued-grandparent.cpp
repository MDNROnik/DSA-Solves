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
    void fun(TreeNode* root, int gp, int p, int &ans){
        if(root==NULL){
            return ;
        }
        if(gp%2==0){
            ans+=root->val;
        }
        gp = p;
        p = root->val;
        fun(root->left, gp, p, ans);
        fun(root->right, gp, p, ans);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0,gp=1,p=root->val;
        fun(root->left,gp,p,ans);
        fun(root->right,gp,p,ans);
        return ans;
    }
};
