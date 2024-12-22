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
    TreeNode* fun(vector<int> pre, vector<int> in){

        if (pre.empty() || in.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[0]);

        vector<int>pre1,pre2;
        vector<int>in1,in2;
        int i=0,j=1;
        int n=pre.size();
        for(i=0,j=1;i<n;i++,j++){
            if(in[i]==pre[0]){i=i+1;break;}
            in1.push_back(in[i]);
            pre1.push_back(pre[i+1]);
        }
        for(;i<n;i++){
            in2.push_back(in[i]);
            pre2.push_back(pre[i]);
        }

        


        // for(int i=0;i<in1.size();i++){
        //     cout<<in1[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<in2.size();i++){
        //     cout<<in2[i]<<" ";
        // }
        // cout<<endl;



        

        root->left = fun(pre1, in1);
        root->right = fun(pre2, in2);

        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int l=0, r= pre.size();
        return fun(pre, in);
    }
};