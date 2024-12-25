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
    int fun(TreeNode* root, int &ans){
        int left=-1001,right=-1001;
        if(root->left!=NULL){
            left=fun(root->left,ans);
            ans = max(ans, left);
        }
        else{left=0;}
        if(root->right!=NULL){
            right=fun(root->right,ans);
            ans = max(ans, right);
        }
        else{right=0;}
        int value = root->val; ans = max(ans,value);
        int v = value+left; ans= max(ans, v);
        int v2 = value+right; ans = max(ans, v2);
        int v3 = value+right+left; ans = max(ans, v3);

        
        return max(max(v,v2), value);
        
        
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1001;
        
        fun(root,ans);
        return ans;
    }
};