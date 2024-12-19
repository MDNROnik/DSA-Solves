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
    int maxDepth(TreeNode* root, int &ma) {
        if(root==NULL){return 0;}
        int l = maxDepth(root->left,ma);
        int r = maxDepth(root->right,ma);
        ma = max(ma,(l+r));
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ma = 0;
        int l = maxDepth(root->left,ma);
        int r = maxDepth(root->right,ma);
        cout<<l<<" "<<r<<endl;
        return max((l+r),ma);
    }
};