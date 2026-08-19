class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> m;
        for(auto &v:reservedSeats)
        {
            if(m.count(v[0]))
            m[v[0]][v[1]-1]=0;
            else
            {
                m[v[0]].resize(10,1);
                m[v[0]][v[1]-1]=0;
            }
        }
        long long ans=2LL*(n-m.size());
        for(auto &[c,arr]:m)
        {
            int f1=0,f2=0;
            if(arr[1]&&arr[2]&&arr[3]&&arr[4])
            {
                f1=1;
                ans++;
            }
            if(arr[7]&&arr[8]&&arr[5]&&arr[6])
            {
                f2=1;
                ans++;
            }
            if((!f1)&&(!f2)&&arr[3]&&arr[4]&&arr[5]&&arr[6])
            ans++;
        }
        return ans;
    }
};