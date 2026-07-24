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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return NULL;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> min_heap;
    for(int i=0;i<lists.size();i++)
    {
        if(lists[i]!=NULL)
        {
        min_heap.push({lists[i]->val,lists[i]});
        }
    }
        while(!min_heap.empty())
        {
            ListNode* curr=min_heap.top().second;
            min_heap.pop();
            prev->next=curr;
            prev=prev->next;
            if(curr->next!=NULL)
            {
                min_heap.push({curr->next->val, curr->next});
            }
        }
        return dummy->next;
        
    }
};