/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        vector<vector<int>>v2(1000);
        int l=0;
        while(!q.empty()){
            pair<Node*, int> p =q.front();
            Node* now = q.front().first;
            int level = q.front().second;
            v2[level].push_back(now->val);
            vector<Node*> child = q.front().first->children;
            for(int i=0;i<child.size();i++){
                q.push({child[i],level+1});
                l= max(l, level+1);
            }
            q.pop();
        }
        for(int i=0;i<=l;i++){
            if(v2[i].size()>0){
                cout<<v2[i].size()<<endl;
                v.push_back(v2[i]);
            }
        }

        return v;
    }
};