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
    void recursion(TreeNode* root,int level,map<int,vector<int>>&mp){
        if(root==NULL){
            mp[level].push_back(-101);
            return;
        }
        //cout<<root->val<<endl;
        mp[level].push_back(root->val);
        recursion(root->left,level+1,mp);
        recursion(root->right,level+1,mp);
    }
    bool isSymmetric(TreeNode* root) {
        map<int,vector<int>>mp;
        recursion(root,0,mp);
        bool ans=true;
        for(auto a=mp.begin();a!=mp.end();a++){
            vector<int>v=a->second;
            int i=0,j=v.size()-1;
            //cout<<a->first<<" "<<v.size()<<endl;
            if(v.size()%2!=0 && a->first>0){
                //cout<<a->first<<endl;
                ans=false;break;
            }
            while(i<j){
                if(v[i]!=v[j]){
                    ans=false;break;
                }
                i++,j--;
            }
            if(ans==false){break;}
        }
        return ans;
    }
};