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
    bool hasPathSum2(TreeNode* root, int targetSum) {

        //targetSum = (targetSum-root->val);

        if(targetSum==0 && root==NULL){
            return true;
        }
        else if(targetSum !=0 && root==NULL){
            return false;
        }
        // else if(targetSum==0 && root!=NULL){
        //     return false;
        // }
        targetSum = (targetSum-(root->val));
        if(root->left!=NULL && root->right!=NULL){
            return ( hasPathSum2(root->left, targetSum) || hasPathSum2(root->right, targetSum) );
        }
        else if(root->left!=NULL){
            return hasPathSum2(root->left, targetSum);
        }
        return hasPathSum2(root->right, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        //cout<<1-(-1)<<endl;
        targetSum = (targetSum-(root->val) );
        if(root->left!=NULL && root->right!=NULL){
            return ( hasPathSum2(root->left, targetSum) || hasPathSum2(root->right, targetSum) );
        }
        else if(root->left!=NULL){
            return hasPathSum2(root->left, targetSum);
        }
        return hasPathSum2(root->right, targetSum);
    };
};