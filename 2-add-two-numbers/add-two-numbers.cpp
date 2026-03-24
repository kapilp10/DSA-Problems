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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    ListNode* temp=new ListNode();
    ListNode* curr= temp;
    int c=0;

    while(l1!=NULL || l2!=NULL || c!=0)
    {
        int d1=(l1!=NULL) ? l1->val:0;
        int d2=(l2!=NULL) ? l2->val:0;
        int val= d1+d2+c;
        c=val/10;
        val=val%10;

        curr->next=new ListNode(val);
        curr=curr->next;
        l1=(l1!= NULL) ? l1->next : NULL;
        l2=(l2!= NULL) ? l2->next : NULL;


    }
    return temp->next;
        
    }
};