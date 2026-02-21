class Solution 
{
 public:
 bool isPrime(int n) 
 {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0) return false;
    }
    return true;
 }
    int helper(int l,int r)
    {
        int f=0;

        for(int i=l;i<=r;i++)
        {
           int bitCount=0;
           int temp=i;
            while(temp>0)
            {
                temp=temp&(temp-1);
                bitCount+=1;
            }
            if(isPrime(bitCount))
            {
              f+=1;
            }
        }
        return f;
    }
    int countPrimeSetBits(int left, int right) 
    {
        return helper(left,right);
        
    }
};