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
        stack<int> t;
         ListNode* temp=head;
         while(temp!=NULL)
         {
            t.push(temp->val);
            temp=temp->next;
         }
          temp=head;
          int v;

         while(!t.empty())
         {
            v=t.top();
            temp->val=v;
            temp=temp->next;
            t.pop();
         }
         return head;
    }
};