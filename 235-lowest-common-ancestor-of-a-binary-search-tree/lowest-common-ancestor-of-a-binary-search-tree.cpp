/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void setparent(TreeNode* root, map<long long,long long> &parent, int value){
        if(root==NULL){return;}
        parent[root->val]=value;
        setparent(root->left,parent,root->val);
        setparent(root->right,parent,root->val);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<long long,long long>parent,parents;
        long long grand = 1000000005;
        parent[root->val] = grand;
        setparent(root->left,parent,root->val);
        setparent(root->right,parent,root->val);
        // for(auto a=parent.begin();a!=parent.end();a++){
        //     cout<<a->first<<" "<<a->second<<endl;
        // }
        // TreeNode* n = new TreeNode(6);

        while(p->val != grand){
            parents[p->val]++;
            p->val = parent[p->val];
        }
        // for(auto a=parents.begin();a!=parents.end();a++){
        //     cout<<a->first<<" "<<a->second<<endl;
        // }cout<<endl;
        int ans = INT_MAX;
        while(q->val != grand){
            parents[q->val]++;
            if(parents[q->val]>=2){
                ans = min(ans,q->val);break;
            }
            q->val = parent[q->val];
        }
        // for(auto a=parents.begin();a!=parents.end();a++){
        //     cout<<a->first<<" "<<a->second<<endl;
        // }
        //cout<<root->val<<endl;
        root->val = ans;
        return root;
    }
};