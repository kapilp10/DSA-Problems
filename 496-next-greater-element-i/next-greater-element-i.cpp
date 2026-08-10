class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> nge;
        stack<int> st;
        for(auto num : nums2)
        {
            while(!st.empty() && st.top()<num)
            {
                nge[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> res;
        for(auto num : nums1)
        {
            if(nge.count(num))
            {
                res.push_back(nge[num]);
            }
            else
            {
                res.push_back(-1);
            }
        }
       return res;
    }
};