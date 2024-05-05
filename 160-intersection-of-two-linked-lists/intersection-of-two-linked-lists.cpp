/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *fun(ListNode *tempa, ListNode *tempb,int remain){
        //cout<<remain<<endl;
        while(remain>0){
            remain--;
            tempb=tempb->next;
        }
        while(tempb!=NULL){
            if(tempb==tempa){
                return tempb;
            }
            tempa=tempa->next;
            tempb=tempb->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempa=headA;
        ListNode *tempb=headB;
        int a=0,b=0;
        while(tempa!=NULL || tempb!=NULL){
            if(tempa!=NULL){
                a++;
                tempa=tempa->next;
            }
            if(tempb!=NULL){
                b++;
                tempb=tempb->next;
            }
        }
        //cout<<a<<" "<<b<<endl;
        if(a<b){
            return fun(headA, headB, b-a);
        }
        else{
            return fun(headB, headA, a-b);
        }

    }
};