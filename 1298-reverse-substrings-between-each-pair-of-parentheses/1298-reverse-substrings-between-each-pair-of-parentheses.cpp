class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<string> st;
        int n=s.size();
        int co=0;
        for(int i=0;i<n;i++)
        {
            string c=string(1,s[i]);
            if(c!=")")
            st.push(c);
            else
            {
                string t="";
                while(st.top()!="(")
                {
                    t=st.top()+t;
                    st.pop();
                }
                reverse(t.begin(),t.end());
                st.pop();
                if(st.empty())
                ans+=t;
                else
                st.push(t);
            }
        }
        stack<string> stt;
        while(!st.empty())
        {
            stt.push(st.top());
            st.pop();
        }
        while(!stt.empty())
        {
            ans+=stt.top();
            stt.pop();
        }
        return ans;
    }
};