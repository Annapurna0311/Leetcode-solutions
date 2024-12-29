class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int x = values[0];
        int maxi = 0;
        for(int i=1;i<values.size();i++){
            int y = values[i] - i;
            maxi = max(maxi , x + y);
            int z = values[i] + i;
            x = max(x , z);
        }
        return maxi;
    }
};