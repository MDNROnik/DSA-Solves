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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL){ cout<<111<<endl; return true;}
        else if(p==NULL && q!=NULL){cout<<222<<endl;return false;}
        else if(p!=NULL && q==NULL){cout<<333<<endl;return false;}
        else if(p->val==q->val){
            cout<<p->val<<" "<<q->val<<endl;
            return ( isSameTree(p->left,q->left) && isSameTree(p->right,q->right) ) ;
        }
        else{
            cout<<p->val<<" "<<q->val<<endl;
            return false;
        }
    }
};