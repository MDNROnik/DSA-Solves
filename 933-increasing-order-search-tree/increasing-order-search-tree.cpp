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
void inOrderTrav(TreeNode * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> val);
  inOrderTrav(curr -> right, inOrder);
}
void setInorder(TreeNode* root, vector < int > & inOrder, int &i){
    if(i==inOrder.size()){
        return;
    }
    root->val=inOrder[i];
    i+=1;
    if(i==inOrder.size()){
        return;
    }
    else{
        TreeNode* right = new TreeNode();
        root->right=right;
    }
    setInorder(root->right,inOrder,i);
}
    TreeNode* increasingBST(TreeNode* root) {
        vector < int > inOrder;
        inOrderTrav(root, inOrder);
        int i=0;
        TreeNode* ans = new TreeNode();
        setInorder(ans,inOrder,i);
        return ans;
    }
};