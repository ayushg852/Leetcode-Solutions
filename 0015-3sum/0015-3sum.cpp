class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            if(i>0&&arr[i]==arr[i-1])
            continue;
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int s=1LL*arr[i]+arr[l]+arr[r];
                if(s<0)
                l++;
                else if(s>0)
                r--;
                else
                {
                    ans.push_back({arr[i],arr[l],arr[r]});
                    l++;
                    r--;
                    while(l<r && arr[l]==arr[l-1])
                    l++;
                    while(l<r && arr[r]==arr[r+1])
                    r--;
                }
            }  
        }
        return ans;
    }
};