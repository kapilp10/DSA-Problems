class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> temp;
        int j=0;
        for(int i=0;i<pushed.size();i++)
        {
            temp.push(pushed[i]);
            while(!temp.empty()&&temp.top()==popped[j])
            {
                temp.pop();
                j++;
            }


        }
        return temp.empty();
        

        
    }
};