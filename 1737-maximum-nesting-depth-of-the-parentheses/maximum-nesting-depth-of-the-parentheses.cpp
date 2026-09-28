class Solution {
public:
    int maxDepth(string s) 
    {
        stack<char> st;
        int l=0;
        int r=0;
        int c=INT_MIN;
        for(char i: s)
        {
            if(i=='(')
            {
                st.push('(');
                l++;
            }
            else if(i==')')
            {
                st.pop();
                l--;
            }
            c=max(c,l);
        }
        return c;
    }
};