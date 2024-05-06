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
    void fun(vector<int>&ans , Node* root){
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        for(auto a : root->children){
            fun(ans,a);
        }
        return;
    }
    vector<int> preorder(Node* root) {
         vector<int>ans;
         fun(ans, root);
         
         return ans;
    }
};