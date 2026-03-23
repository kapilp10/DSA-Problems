class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        queue<int> q; 
        int n=students.size();
        int c=0;
        int i=0;
        for (const auto& elem : students) 
        {
        q.push(elem);
        }
        while(q.size()>0&&c!=q.size())
        {
            if(q.front()==sandwiches[i])
            {
                c=0;
                q.pop();
                i++;
            }
            else
            {
               int x= q.front();
               q.pop();
               q.push(x);
               c++;
            }
        }
        return q.size();
    }
};