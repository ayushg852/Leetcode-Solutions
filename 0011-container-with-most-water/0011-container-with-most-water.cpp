#define ll long long
class Solution {
public:
    int maxArea(vector<int>& arr) {
        ll l=0;
        ll r=arr.size()-1;
        ll ans=0;
        while(l<r)
        {
            ans=max(ans,(r-l)*min(arr[l], arr[r]));
            if(arr[l]<arr[r])
            l++;
            else
            r--;
        }
        return ans;
    }
};