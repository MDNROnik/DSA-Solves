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
    void inOrderTrav(TreeNode * cur, map<int,int>& inOrder, bool& ans, int& k){
        if(cur==NULL || ans==true){
            return;
        }
        inOrderTrav(cur->left, inOrder,ans,k);
        inOrder[cur->val]++;
        //cout<<cur->val<<endl;
        int remain=k-cur->val;
        
        if(remain==cur->val && (inOrder[remain]-1)>0){
            ans=true;
            return;
        }
        else if(inOrder[remain]==1 && remain!=cur->val){
            ans=true;
            return;
        }
        
        inOrderTrav(cur->right, inOrder,ans,k);
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int> inOrder;

        bool ans=false;
        inOrderTrav(root, inOrder,ans,k);
        return ans;
    }
};