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
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    void fun(TreeNode* root, int &count ,  int maxi){
        if(root==NULL){
            return ;
        }
        if( root->val >= maxi ){
            maxi = root->val;count++;
        }
        fun(root->left,count,maxi);
        fun(root->right,count,maxi);
        return;
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        if(root==NULL){
            return count;
        }
        int maxi = root->val;
        fun(root,count,maxi);

        return count;
    }
};