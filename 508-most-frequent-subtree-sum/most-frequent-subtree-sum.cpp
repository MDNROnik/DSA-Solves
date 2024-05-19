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
    int solve(TreeNode* root, map<int,int> &mp){
        if(root==NULL){
            return 0;
        }
        int value = root->val+solve(root->left,mp)+solve(root->right,mp);
        mp[value]++;
        return value ;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>mp;
        solve(root,mp);
        priority_queue< pair<int,int> > pq;
        for(auto a=mp.begin();a!=mp.end();a++){
            pq.push({a->second,a->first});
        }
        int now=pq.top().first;
        vector<int>v;
        
        while(pq.size()>0){
            if(now==pq.top().first){
                v.push_back(pq.top().second);
            }
            else{
                break;
            }
            pq.pop();
        }
        
        return v;
    }
};