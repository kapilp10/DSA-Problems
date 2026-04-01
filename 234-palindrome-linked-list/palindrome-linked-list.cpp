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
    bool isPalindrome(ListNode* head) {
        stack<int> r;
        ListNode* temp=head;
        while(temp!=NULL)
        {
           r.push(temp->val);
           temp=temp->next;
        }
        temp=head;

        while(temp!=NULL)
        {
            int t=r.top();
            if(temp->val!=t)
            {
             return false;
            }
            temp=temp->next;
            r.pop();
        }
        return true;
        
    }
};