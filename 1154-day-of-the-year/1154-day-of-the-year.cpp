class Solution {
public:
    int dayOfYear(string date) {
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        int days=day;
        for(int i=1;i<month;i++)
        {
            if(i==2)
            {
                if(year%4!=0)
                days+=28;
                else if(year%100==0)
                {
                    if(year%400==0)
                    days+=29;
                    else
                    days+=28;
                }
                else
                days+=29;
            }
            else if(i<=7)
            {
                if(i%2==1)
                days+=31;
                else
                days+=30;
            }
            else
            {
                if(i%2==0)
                days+=31;
                else
                days+=30;
            }
        }
        return days;
    }
};