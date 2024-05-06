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
    TreeNode* fun(TreeNode* root1, TreeNode* root2){
        if(root1==root2 && root1==NULL){
            return NULL;
        }
        else if(root2!=NULL && root1!=NULL){
            //cout<<root1->val<<" "<<root2->val<<endl;
            root1->val+=root2->val;
            //cout<<root1->val<<endl;
        }
        else if(root1==NULL){
            //cout<<root2->val<<endl;
            return root2;
        }
        else if(root2==NULL){
            return root1;
        }
        TreeNode* now = fun(root1->left, root2->left);
        if(now == NULL){
            //cout<<root1->val<<endl;
        }
        else{
            root1->left=now;
        }
        TreeNode* now2 = fun(root1->right, root2->right);
        if(now2 == NULL){

        }
        else{
            //cout<<now2->val<<endl;
            root1->right=now2;
        }
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL){
            return root2;
        }
        else if(root2==NULL){
            return root1;
        }
        TreeNode* ans=root1;
        fun(root1,root2);

        return ans;
    }
};