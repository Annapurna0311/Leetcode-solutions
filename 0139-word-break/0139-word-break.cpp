class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        queue<int> q;
        vector<bool> vis(s.size(),false);
        q.push(0);
        while(!q.empty()){
            int start = q.front();
            q.pop();
            if(start == s.size()){
                return true;
            }
            for(int end = start+1;end<=s.size();end++){
                if(vis[end]){
                    continue;
                }
                if(st.find(s.substr(start , end - start))!=st.end()){
                    q.push(end);
                    vis[end] = true;
                }
            }
        }
        return false;
    }
};