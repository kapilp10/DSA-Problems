class Solution {
public:
    int n;

    int nextIndex(vector<vector<int>>& jobs, int l, int currJobEnd)
    {
        int res = n;
        int h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (jobs[mid][0] > currJobEnd)
            {
                h = mid - 1;
                res = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        vector<vector<int>> jobs(n, vector<int>(4, 0));
        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = intervals[i][0];
            jobs[i][1] = intervals[i][1];
            jobs[i][2] = intervals[i][2];
            jobs[i][3] = i;
        }
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){ return a[0] < b[0]; });

        vector<array<long long,5>> score(n + 1);
        vector<array<array<int,4>,5>> list(n + 1);   
        vector<array<int,5>> len(n + 1); 

        for (int k = 0; k <= 4; k++) { score[n][k] = 0; len[n][k] = 0; }

        for (int i = n - 1; i >= 0; i--)
        {
            int next = nextIndex(jobs, i + 1, jobs[i][1]);
            for (int k = 0; k <= 4; k++)
            {
                if (k == 0) { score[i][k] = 0; len[i][k] = 0; continue; }

                long long takenScore = jobs[i][2] + score[next][k - 1];
                long long notTakenScore = score[i + 1][k];

                if (takenScore > notTakenScore)
                {
                    score[i][k] = takenScore;
                    
                    array<int,4> tmp = list[next][k - 1];
                    int L = len[next][k - 1];
                    tmp[L] = jobs[i][3];
                    L++;
                    sort(tmp.begin(), tmp.begin() + L);
                    list[i][k] = tmp;
                    len[i][k] = L;
                }
                else if (notTakenScore > takenScore)
                {
                    score[i][k] = notTakenScore;
                    list[i][k] = list[i + 1][k];
                    len[i][k] = len[i + 1][k];
                }
                else
                {
                   
                    array<int,4> tmp = list[next][k - 1];
                    int L1 = len[next][k - 1];
                    tmp[L1] = jobs[i][3];
                    L1++;
                    sort(tmp.begin(), tmp.begin() + L1);

                    array<int,4>& other = list[i + 1][k];
                    int L2 = len[i + 1][k];

                    bool takeIsSmaller = lexicographical_compare(
                        tmp.begin(), tmp.begin() + L1,
                        other.begin(), other.begin() + L2
                    );

                    score[i][k] = takenScore; 
                    if (takeIsSmaller || L2 == 0)
                    {
                        list[i][k] = tmp; len[i][k] = L1;
                    }
                    else
                    {
                        list[i][k] = other; len[i][k] = L2;
                    }
                }
            }
        }

        vector<int> ans(list[0][4].begin(), list[0][4].begin() + len[0][4]);
        return ans;
    }
};