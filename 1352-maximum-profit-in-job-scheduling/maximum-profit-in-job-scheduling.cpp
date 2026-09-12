class Solution {
public:
    int memo[50001];
    int n;
    
    int nextIndex(vector<vector<int>>& jobs,int l,int currJobEnd)
    {
        int res=n+1;
        int h=n-1;
        while(l<=h)
        {
        int mid=l+(h-l)/2;
        if(jobs[mid][0]>=currJobEnd)
        {
            h=mid-1;
            res=mid;
        }
        else
        {
            l=mid+1;
        }
        }
        return res;
    }
    int solve(vector<vector<int>>& jobs,int i)
    {
        if(i>=n)
        {
            return 0;
        }
        if(memo[i]!=-1)
        {
            return memo[i];
        }
        int next=nextIndex(jobs,i+1,jobs[i][1]);
        int taken=jobs[i][2]+solve(jobs,next);
        int not_taken=solve(jobs,i+1);
        return memo[i] = max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        memset(memo,-1,sizeof(memo));
        vector<vector<int>> jobs(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            jobs[i][0]=startTime[i];
            jobs[i][1]=endTime[i];
            jobs[i][2]=profit[i];
        }

        auto comp=[&](auto& vec1,auto& vec2)
        {
            return vec1[0]<vec2[0];
        };

        sort(jobs.begin(),jobs.end(),comp);
        return solve(jobs,0);
        
    }
};