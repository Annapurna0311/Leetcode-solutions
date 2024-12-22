class Solution {
public:
    long long findScore(vector<int>& nums) {
       priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
       for(int i=0;i<nums.size();i++){
            pq.push({nums[i] , i});
            nums[i] = 0;
       }
       long long score = 0;
       while(!pq.empty()){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            // if(nums[idx]==1){
            //     continue;
            // }
            if(nums[idx]==0){
                score += num;
                for(int i=-1;i<=1;i++){
                    int adj = idx + i;
                    if(adj >=0 and adj<nums.size()){
                        nums[adj] = 1;
                    }
                }
            }
       }
        return score;
    }
};