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
int ans = 0;
    int fun(TreeNode* root){
        if(root==nullptr){return 0;}

        int left = fun(root->left);
        int right = fun(root->right);

        if(root->left!=NULL && root->val==root->left->val){
            left+=1;
        }
        if(root->right!=NULL && root->val==root->right->val){
            right+=1;
        }
        
        if(root->left!=NULL && root->right!=NULL && root->left->val==root->val && root->right->val==root->val){
            int v=left+right;
            ans = max(ans,v);
            return max(left,right);
        }
        else if(root->left!=NULL &&  root->left->val==root->val){
            ans = max(ans,left);
            return left;
        }
        else if(root->right!=NULL &&  root->right->val==root->val){
            ans = max(ans,right);
            return right;
        }
        else{
            return 0;
        }


        
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){return 0;}
        fun(root);

        return ans;
    }
};