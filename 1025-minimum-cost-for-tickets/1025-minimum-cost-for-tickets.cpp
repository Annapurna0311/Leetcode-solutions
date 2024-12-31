class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size()-1];
        vector<int> dp(lastDay+1,0);
        int i =0;
        for(int a =1;a<=lastDay;a++){
            if(a<days[i]){
                dp[a] = dp[a-1];
            }
            else{
                i++;
                dp[a] = min({dp[a-1]+costs[0],dp[max(0, a - 7)] + costs[1],
                               dp[max(0, a - 30)] + costs[2]});
            }
        }
        return dp[lastDay];
    }
};