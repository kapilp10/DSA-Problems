class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<arr.size();i++)
        {
            maxHeap.push({abs(arr[i]-x),arr[i]});
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
        vector<int> res;
        while(!maxHeap.empty())
        {
            int i=maxHeap.top().second;
            res.push_back(i);
            maxHeap.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};