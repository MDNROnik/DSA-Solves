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
public:
    int fun(TreeNode* root, TreeNode* p, TreeNode* q, int &ans){
        if(root==NULL){
            return 0;
        }

        //cout<<root->val<<endl;

        if(ans!=-1000000000){return 0;}
        int count = 0;
        if(root->val==p->val || root->val==q->val){
            count++;
        }
        int l = fun(root->left,p,q,ans);
        if(ans!=-1000000000){return 0;}
        int r = fun(root->right,p,q,ans);
        if(ans!=-1000000000){return 0;}

        cout<<root->val<<" ROOT "<<endl;
        cout<< count<<" "<<l<<" "<<r<<endl<<endl;;

        if(count+l+r == 2){
            ans = root->val;
            
            return 0;
        }
        return count+l+r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int ans = -1000000000;
        fun(root,p,q,ans);
        root->val=ans;
        return root;
    }
};