/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){return head;}
        ListNode* temp = NULL;
        while(head != NULL){
            ListNode* head2 = head->next;
            head->next = temp;
            temp=head;
            head=head2;
        }
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || head==NULL){return head;}
        ListNode* preHead = head;
        ListNode* now = head;
        ListNode* now2 = head;
        ListNode* postHead;
        left--;right--;
        while(left-- && right--){
            preHead = now;
            now = now->next;
            now2 = now2->next;
        }
        int leftIsHead = 0;
        if(now==head){
            preHead = NULL;
            leftIsHead = 1;
        }
        while(right--){
            now2 = now2->next;
        }
        int rightIsNull = 0;
        if(now2->next==NULL){
            rightIsNull = 1;
        }
        cout<<now->val<<" "<<now2->val<<endl;
        postHead = now2->next;
        now2->next = NULL;
        ListNode*  newHead = reverseList(now);
        if(leftIsHead==0){
            preHead->next = newHead;
        }
        else{
            head = newHead;
        }
        while(newHead->next != NULL){
            cout<<newHead->val<<endl;
            newHead = newHead->next;
        }
        newHead->next = postHead;
        
        return head;
    }
};