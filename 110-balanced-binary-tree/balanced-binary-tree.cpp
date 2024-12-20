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
    int maxDepth(TreeNode* root, bool &ma) {
        if(root==NULL || ma==false){return 0;}
        int l = maxDepth(root->left,ma);
        int r = maxDepth(root->right,ma);

        int dif = abs(l-r);
        if(dif >1 ){ma=false;return 0;}
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        maxDepth(root,ans);
        return ans;
    }
};