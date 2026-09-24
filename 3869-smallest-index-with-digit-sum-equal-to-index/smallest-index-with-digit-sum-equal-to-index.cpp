class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        int n=nums.size();
        int digit;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            int temp=nums[i];
            while(temp!=0)
            {
                digit=temp%10;
                sum+=digit;
                temp=temp/10;
            }
            if(sum==i)
            {
                return i;
            }
        }
        return -1;
    }
};