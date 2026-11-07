class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> avail;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> unavail;
        for (int i = 0; i < n; i++)
        avail.push({servers[i], i});       
        vector<int> ans(m);
        long long current_time = 0;
        for (int i = 0; i < m; i++)
        {
            current_time = max(current_time, (long long)i);
            if (avail.empty())
            current_time = get<0>(unavail.top());            
            while (!unavail.empty() && get<0>(unavail.top()) <= current_time)
            {
                auto [free_time, weight, idx] = unavail.top();
                unavail.pop();
                avail.push({weight, idx});
            }
            auto [weight, idx] = avail.top();
            avail.pop();
            ans[i] = idx;
            unavail.push({current_time + tasks[i], weight, idx});
        }
        return ans;
    }
};
