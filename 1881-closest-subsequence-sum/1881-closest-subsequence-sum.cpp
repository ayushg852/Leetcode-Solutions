class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> s1;
        for (int mask = 0; mask < (1 << mid); mask++) {
            int s = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i))
                    s += nums[i];
            }
            s1.push_back(s);
        }

        vector<int> s2;
        int no_in_second = n - mid;
        for (int mask = 0; mask < (1 << no_in_second); mask++) {
            int s = 0;
            for (int i = 0; i < no_in_second; i++) {
                if (mask & (1 << i))
                    s += nums[i + mid];
            }
            s2.push_back(s);
        }
        
        sort(s2.begin(), s2.end());

        int ans = INT_MAX;
        for (int i = 0; i < (1 << mid); i++) {
            int target = goal - s1[i];
            auto it = upper_bound(s2.begin(), s2.end(), target);
            if (it != s2.end()){
                ans = min(ans, abs(goal - (s1[i] + (*it))));
            }
            if (it != s2.begin()) {
                it--;
                ans = min(ans, abs(goal - (s1[i] + (*it))));
            }
        }
        return ans;
    }
};