class Solution {
public:
    long long coloredCells(int n) {
        long long x = 1;
        int add = 4;
        while(--n){
            x += add;
            add += 4;
        }
        return x;
    }
};