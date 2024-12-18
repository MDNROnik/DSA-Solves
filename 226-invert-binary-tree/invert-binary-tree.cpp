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
    TreeNode* fun(TreeNode* root){
        if(root==NULL){
            return root;
        }
        TreeNode* l = fun(root->left);
        TreeNode* r = fun(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        TreeNode* l = fun(root->left);
        TreeNode* r = fun(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
};