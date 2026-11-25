class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int ans=0;
        int p=-1;
        int i=0;
        while(i<n)
        {
            while(i<n&&seats[i]==0)
            i++;
            if(p==-1)
            ans=i;
            else if(i==n)
            ans=max(ans,i-p-1);
            else
            ans=max(ans,((i-p)/2));
            p=i;
            i++;
        }
        return ans;
    }
};