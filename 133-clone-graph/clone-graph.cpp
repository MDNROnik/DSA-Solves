/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        map<int,Node*>visit;
        return cloneG(node, visit);
    }
    Node* cloneG(Node* node, map<int,Node*>& visit){
        Node *nnode =  new Node(node->val);
        visit[node->val] = nnode;

        vector<Node*> n = node->neighbors;
        for(int i=0;i<n.size();i++){
            auto it = visit.find(n[i]->val);

            if(it == visit.end()){
                nnode->neighbors.push_back(   cloneG(n[i],visit)  );
            }
            else{
                nnode->neighbors.push_back(it->second);
            }
        }

        return nnode;
    }
};