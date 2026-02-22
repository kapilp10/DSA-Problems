class Solution {
public:
// string dec_to_bin(int num)
// {
//     vector<int> bin;
//     int i=0;
//     while(num>0)
//     {
//         bin.push_back(num%2);
//         num=num/2;
//         i++;
//     }

// }
    int binaryGap(int n) 
    {
        int maxGap = 0;
        int currentGap = -1;

        while (n != 0) {
            if ((n & 1) == 1) {
                if (currentGap != -1) {
                    maxGap = max(maxGap, currentGap);
                }
                currentGap = 1;
            } else {
                if (currentGap != -1) {
                    currentGap++;
                }
            }
            n >>= 1;
        }

        return maxGap;
        
    }
};