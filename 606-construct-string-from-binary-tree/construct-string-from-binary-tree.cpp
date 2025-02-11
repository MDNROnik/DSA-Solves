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
    void fun(TreeNode* root, string &ans){
        if(root==NULL){
            return ;
        }
        ans.append("(");
        string stri = to_string(root->val);
        ans.append(stri);
        if(root->left==NULL && root->right!=NULL){
            ans.append("()");
        }
        fun(root->left, ans);
        fun(root->right, ans);
        ans.append(")");
        return ;
    }
    string tree2str(TreeNode* root) {
        string ans ="";
        fun(root, ans);
        int n = ans.size();
        ans.erase(ans.begin() + n-1);
        ans.erase(ans.begin() + 0);
        return ans;
    }
};