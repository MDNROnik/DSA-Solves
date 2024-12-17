/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* n = new Node(-1);
        Node* temp = head;
        Node* nhead = n;
        map<Node*,Node*>mp;
        while(temp!=NULL){
            Node* t = new Node(temp->val);
            n->next = t;
            n=n->next;
            mp[temp]=n;
            temp=temp->next;
        }
        temp = head;
        Node* temp2 = nhead->next;
        //cout<<mp[head->random]<<endl;
        while(temp!=NULL){
            temp2->random = mp[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return nhead->next;
    }
};