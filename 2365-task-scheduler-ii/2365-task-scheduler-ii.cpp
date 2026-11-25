class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long d=1;
        unordered_map<int,long long> m;
        for(auto &i:tasks)
        {
            if(m.count(i)&&d<=m[i])
            d=m[i]+1;
            m[i]=d+space;
            d++;
        }
        return d-1;
    }
};