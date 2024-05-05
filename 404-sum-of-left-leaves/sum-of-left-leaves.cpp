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
    bool fun(TreeNode* root, int &sum, char c){
        if(root==NULL){
            if(c=='l'){
                return true;
            }
            else{
                return false;
            }
        }
        bool left = fun(root->left,sum,'l');
        bool right = fun(root->right,sum,'r');

        if(left==true && c=='l' && root->left==NULL && root->right==NULL){
            cout<<root->val<<endl;
            sum+=root->val;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        fun(root,sum,'c');
        return sum;
    }
};