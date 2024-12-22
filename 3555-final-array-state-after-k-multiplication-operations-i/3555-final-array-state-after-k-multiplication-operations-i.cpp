class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) { 
            int mini = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] < nums[mini]){
                    mini = j;
                }
            }
            nums[mini]*= multiplier;
        }
       
        return nums;

    }
};

// 2 , 2 , 3 , 5, 6
// 4 , 2 , 3, 5 , 6
// 4 , 4 , 3 , 5 , 6
// 4 , 4 , 6 , 5 , 6
// 8 , 4 , 6, 5 , 6

