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
void solve(TreeNode* root,vector<int>& s,vector<vector<int>>&ans){
    if(!root){
        return ;
    }
    s.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        //cout<<root->val<<endl;
        // for(int i=0;i<s.size();i++){
        //     cout<<s[i]<<" ";
        // }
        // cout<<endl;
        ans.push_back(s);
    }
    solve(root->left,s,ans);
    solve(root->right,s,ans);
    s.pop_back();
    return;
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>str;
        solve(root,str,ans);
        vector < string > vc;
        map<string,int>mp;
        for(int i=0;i<ans.size();i++){
            vector<int>v=ans[i];
            stringstream ss;
            copy( v.begin(), v.end(), ostream_iterator<int>(ss, "->"));
            string s = ss.str();
            s = s.substr(0, s.length()-2);
            
            //cout<<s.size()<<" -- "<<s<<endl;
            //vc.push_back(s);

            if(mp[s]==0){
                vc.push_back(s);mp[s]=1;
            }
        }
        //cout<<"GO TO THE MAIN"<<endl;
        return vc;
    }
};