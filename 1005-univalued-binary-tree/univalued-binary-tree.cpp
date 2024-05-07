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
    bool fun(TreeNode* root, int value){
        if(root==NULL){return true;}
        if(root->val == value){
            return ( fun(root->left,value) && fun(root->right,value) );
        }
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        return fun(root,value);
    }
};