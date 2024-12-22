class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n-1;
        int h = 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int h = n - mid;
            if(citations[mid] == h){
                return h;
            }
            else if(citations[mid] > h){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return n - l;
    }
};