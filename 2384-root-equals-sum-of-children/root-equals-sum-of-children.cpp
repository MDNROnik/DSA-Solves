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
    bool checkTree(TreeNode* root) {
          if (root == NULL) return 1;
          int child = -101;
          if (root -> left && child==-101) {
            child = root -> left -> val;
          }
          else if (root -> left) {
            child += root -> left -> val;
          }

          if (root -> right && child==-101) {
            child += root -> right -> val;
          }
          if (root -> right) {
            child += root -> right -> val;
          }
          if(child==-101){
              //return 1;
          }
          else if (child != root -> val) {
            //cout<<child<<" "<<root->val<<endl;
            return 0;
          }
          
        
          if( checkTree(root -> left)==0 || checkTree(root -> right)==0 ){
              return 0;
          }
          else{
              return 1;
          }
    }
};