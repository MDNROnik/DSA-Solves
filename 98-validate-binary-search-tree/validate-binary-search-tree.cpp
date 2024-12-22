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
#define ll long long
class Solution {
public:
    bool fun(TreeNode*root, ll mini, ll maxi){
        if(root==NULL){
            return true;
        }
        if(root->val > mini && root->val < maxi){
            return (
                fun(root->left, mini , root->val) 
                &&
                fun(root->right, root->val, maxi)
            );
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        ll mini = -4294967296;
        ll maxi = 4294967296;
        return fun(root,mini,maxi);
    }
};