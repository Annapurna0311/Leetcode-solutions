class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int zeroes = 0;
        int ones = count(s.begin(),s.end(),'1');
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') ones--;
            else zeroes++;
            ans = max(ans , ones+zeroes);
        }
        return ans;
        
    }
};