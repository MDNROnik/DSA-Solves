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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* now = head;
        ListNode* ans = new ListNode(-1);
        ListNode* a = ans;
        int c=0;
        while(now!=NULL){
            int count = 1;
            ListNode* pre = new ListNode(-1);
            ListNode* hstart = now;c=0;
            while(count<=k && now!=NULL){
                count++;
                pre=now;
                now=now->next;
                if(count>k){c=1;}
            }
            if(c==1){
                //cout<<count<<" "<<pre->val<<endl;
                pre->next=NULL;
                hstart = reverseList(hstart);
                //cout<<hstart->val<<endl;
                while(hstart!=NULL){
                    a->next=hstart;
                    a=a->next;
                    pre=hstart;
                    hstart=hstart->next;
                }
                
                pre->next=now;
            }
            if(now==NULL){break;}
        }
        ans = ans->next;
        
        return ans;
    }
};