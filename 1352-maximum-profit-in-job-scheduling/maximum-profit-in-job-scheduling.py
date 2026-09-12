class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        intervals=sorted(zip(startTime,endTime,profit))
        dp={}
        
        def backtrack(i):
            if i == len(intervals):
                return 0
            
            if i in dp:
                return dp[i]
            
            res = backtrack(i+1)
            j=bisect.bisect(intervals,(intervals[i][1],-1,-1))
            dp[i] = res = max(res,intervals[i][2]+backtrack(j))

            return res
        return backtrack(0)