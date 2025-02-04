class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;

        for (int s = 0; s < nums.size(); s++) {
            int curr = nums[s];
            for (int e = s + 1;
                 e < nums.size() && nums[e] > nums[e - 1];
                 e++) {
                curr += nums[e];
            }
            maxSum = max(maxSum, curr);
        }

        return maxSum;
    }
};