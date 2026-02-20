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
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
          v.push_back(temp->val);
          temp=temp->next;
        }       
        vector<int> s;
        s.insert(s.end(),v.begin(),v.end());
        reverse(s.begin(),s.end());
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=s[i])
            {
                return false;
            }
        }
        return true;
    }
};