/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
TreeNode* a=NULL;
public:
    TreeNode* fun(TreeNode* o, TreeNode* c, TreeNode* t, TreeNode* ans){
        
        if(o==NULL && c==NULL){
            return o;
        } 
        else if(o==NULL || c==NULL){
            return NULL;
        }

        TreeNode* left = fun(o->left, c->left, t, ans);
        TreeNode* right = fun(o->right, c->right, t, ans);

        if(left==t || right==t){
            
        }

        if(left==t ){
            return left;
        }
        else if(right==t){
            return right;
        }

        if(left==o->left && right==o->right && o->val==c->val && o==t && a==NULL){
            ans=c;
            a=c;
            return ans;
        }
        else if(left==o->left && right==o->right && o->val==c->val){
            return o;
        }
        return c;
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        TreeNode* ans=NULL;
        fun(o,c,t,ans);
        return a;
    }
};