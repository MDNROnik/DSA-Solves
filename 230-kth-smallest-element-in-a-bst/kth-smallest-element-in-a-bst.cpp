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
    int kthSmallest2(TreeNode* root, vector<int> &v) {
        if(root==NULL){
            return 0;
        }
        v.push_back(root->val);
        kthSmallest2(root->left,v);
        kthSmallest2(root->right,v);
        //sort(v.begin(),v.end());
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        kthSmallest2(root,v);
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        return v[k-1];
    }
};