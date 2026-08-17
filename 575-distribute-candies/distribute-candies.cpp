class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        set<int> s;
        for(auto i: candyType)
        {
            s.insert(i);
        }

        if(s.size()<=candyType.size()/2) 
        {
            return s.size();
        }
        return candyType.size()/2;
        
        
    }
};