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
    void inOrderTrav(TreeNode * curr, int &k, int &ans) {
        if (curr == NULL)
            return;
        if(k<0){
            return;
        }

        inOrderTrav(curr -> left, k,ans);
        k-=1;
        //cout<<curr->val<<" "<<k<<endl;
        if(k==0){
            ans=curr->val;return;
        }
        inOrderTrav(curr -> right, k,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        inOrderTrav(root, k,ans);
        return ans;
    }
};