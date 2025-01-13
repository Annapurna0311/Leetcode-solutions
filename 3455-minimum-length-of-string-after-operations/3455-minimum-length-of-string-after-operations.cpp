class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        int del = 0;
        for(auto &i:mp){
            if(i.second%2==1){
                del += i.second - 1;
            }
            else{
                del += i.second - 2;
            }
        }
        return s.size() - del;
    }
};