class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(auto &x:arr1)
        {
            auto it=lower_bound(arr2.begin(),arr2.end(),x);
            if(it!=arr2.end()&&(*it)-x<=d)
            continue;
            if(it==arr2.begin())
            {
                ans++;
                continue;
            }
            it--;
            if(x-(*it)>d)
            ans++;
        }
        return ans;
    }
};