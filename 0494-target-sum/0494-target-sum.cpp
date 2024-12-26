class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin() , nums.end() , 0);

        if((total_sum - target) % 2 == 1){ 
            return 0;
        }
        int req_sum = (total_sum - target)/2 + target;
        if(req_sum < 0){ 
            return 0;
        }

        vector<int>dp(req_sum + 1 , 0);
        dp[0] = 1;
        for(int i : nums){
            for(int j = req_sum ; j >= i; j--){
                dp[j] += dp[j - i];
            }
        }

        return dp[req_sum];
    }
};