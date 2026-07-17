class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       int count[]={0,0};
        for(auto i: students)
        {
            count[i]=count[i]+1;
        }
        for(auto s: sandwiches)
        {
            if(count[s]==0) break;
            count[s]=count[s]-1;
        }
        return count[0]+count[1];
        
    }
};