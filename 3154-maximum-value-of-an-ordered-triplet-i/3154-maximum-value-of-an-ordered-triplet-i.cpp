class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0 , maxi=0 , dmaxi=0;
        for(int k=0;k<n;k++){
            res = max(res , dmaxi*nums[k]);
            dmaxi = max(dmaxi, maxi - nums[k]);
            maxi = max(maxi , static_cast<long long>(nums[k]));
        }
        return res;
    }
};