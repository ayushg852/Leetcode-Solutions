class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.rbegin(),tasks.rend());
        sort(processorTime.begin(),processorTime.end());
        int n=tasks.size();
        int ans=0;
        for(int i=0;i<n;i+=4)
        ans=max(ans,processorTime[i/4]+tasks[i]);
        return ans;
    }
};