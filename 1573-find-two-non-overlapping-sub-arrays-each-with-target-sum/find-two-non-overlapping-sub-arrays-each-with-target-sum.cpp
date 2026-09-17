class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        // int n=arr.size();
        // int j=0;
        // vector<int> prefSum(n,0);
        // vector<int> suffSum(n,0);
        // int prefCount=0;
        // int suffCount=0;
        // ins currSum=0;
        // for(int i=0;i<=n;i++)
        // {
        //     j++;
        //     currSum+=nums[i];
        //     prefix[i]++;
        //     if(currSum==target) break;
        // }
        // currSum=0;
        // for(int k=j;k<=n;k++)
        // {

        // }
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        int left = 0, sum = 0, ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, dp[left - 1] + len);
                }

                dp[right] = (right > 0) ? min(len, dp[right - 1]) : len;
            } else {
                dp[right] = (right > 0) ? dp[right - 1] : INT_MAX;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};