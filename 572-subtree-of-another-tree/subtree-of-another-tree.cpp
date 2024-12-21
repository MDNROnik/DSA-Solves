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
    void value(TreeNode* root, vector<int> &sub){
        if(root==NULL){
            sub.push_back(-100000);
            return;
        }
        sub.push_back(root->val);
        value(root->left,sub);
        value(root->right,sub);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int>sub;
        value(subRoot,sub);

        vector<int>main;
        value(root,main);


        // for(int i=0;i<sub.size();i++){
        //     cout<<sub[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<main.size();i++){
        //     cout<<main[i]<<" ";
        // }
        // cout<<endl;
        bool ans = false;
        int n=main.size(), m=sub.size();
        for(int i=0;i<n;i++){
            int count=0, k = i;
            for(int j=0;j<m && k<n;j++){
                if(main[k]==sub[j]){

                }
                else{
                    count++;break;
                }
                k++;
            }
            if(count==0){ans=true;break;}
        }
        return ans;
    }
};