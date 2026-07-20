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
int i=0;
    ListNode* insertionSortList(ListNode* head) {
        vector<int> nums;
        ListNode* curr=head;
        ListNode* temp=head;

        while(curr)
        {
         nums.push_back(curr->val);
         curr=curr->next;
        }

        sort(nums.begin(),nums.end());
        
    int s=nums.size();
    while(s)
    {
     head->val=nums[i];
     s--;
     i++;
     head=head->next;
    }
    return temp;
        
    }
};