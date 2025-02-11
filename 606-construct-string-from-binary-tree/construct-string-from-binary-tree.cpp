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
    int fun(TreeNode* root, string &ans, int &now){
        if(root==NULL){
            return 1;
        }
        ans+="("; now+=1;
        string stri = to_string(root->val);
        ans+=stri;now+=1;
        int index = now;
        if(root->left==NULL && root->right!=NULL){
            ans+="()";
        }
        int l = fun(root->left, ans, now);
        int r = fun(root->right, ans, now);
        // str.insert(str.begin() + 8, 'G');
        ans+=")";
        now+=1;
        return 0;
    }
    string tree2str(TreeNode* root) {
        string ans ="";
        int now = -1;
        fun(root, ans, now);
        int n = ans.size();
        ans.erase(ans.begin() + n-1);
        ans.erase(ans.begin() + 0);
        return ans;
    }
};