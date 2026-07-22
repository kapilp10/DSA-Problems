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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* temp=head;
        ListNode* dummy=head;
        vector<int> nums;
        while(temp)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        int x=nums[k-1];
        nums[k-1]=nums[n-k];
        nums[n-k]=x;
        
        for(auto i: nums)
        {
            dummy->val=i;
            dummy=dummy->next;
        }

        return head;
    }
};