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
    void inOrderTrav(TreeNode * curr, int &cnt) {
        if (curr == NULL)
            return;
        
        cnt++;
        inOrderTrav(curr -> left, cnt);
        inOrderTrav(curr -> right, cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;;
        inOrderTrav(root, cnt);
        return cnt;
    }
};