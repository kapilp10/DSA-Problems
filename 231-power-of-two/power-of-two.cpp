class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n>0)
        // {
        // for(int i=0;i<n;i++)
        // {
        //     if(n==pow(2,i))
        //     {
        //     return true;
        //     }
        // }
        // }
        // return false; 
        return n>0 && not(n&n-1);
    }
};