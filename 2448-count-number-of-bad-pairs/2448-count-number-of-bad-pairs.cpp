class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       unordered_map<int,int> mp;
       long long cnt = 0;
       for(int i=0;i<nums.size();i++){
        int dif = i - nums[i];
        int gd = mp[dif];
        cnt += i - gd;
        mp[dif] = gd + 1;
       }
       return cnt;
    }
};