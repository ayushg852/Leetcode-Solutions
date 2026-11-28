class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int max_factor=0;
        int min_price=2e9;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            max_factor=max(max_factor,items[i][0]);
            freq[items[i][0]]++;
            min_price=min(min_price,items[i][1]);
        }
        vector<vector<int>> all_multiples(max_factor+1);
        for(int i=1;i<=max_factor;i++)
        {
            for(int j=i;j<=max_factor;j+=i)
            all_multiples[i].push_back(j);
        }
        vector<pair<int,int>> multiples;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(auto &x:all_multiples[items[i][0]])
            {
                if(freq.count(x))
                {
                    if(x==items[i][0])
                    c+=freq[x]-1;
                    else
                    c+=freq[x];
                }
            }
            if(c>0)
            multiples.push_back({items[i][1],c});
        }
        sort(multiples.begin(),multiples.end());
        int ans=0;
        for(int i=0;i<multiples.size();i++)
        {
            if(multiples[i].first/2>=min_price)
            break;
            if(1LL*budget<=1LL*multiples[i].first*multiples[i].second)
            {
                ans+=2*(budget/multiples[i].first);
                budget-=multiples[i].first*(budget/multiples[i].first);
                break;
            }
            else
            {
                ans+=2*multiples[i].second;
                budget-=multiples[i].first*multiples[i].second;
            }
        }
        ans+=budget/min_price;
        return ans;
    }
};