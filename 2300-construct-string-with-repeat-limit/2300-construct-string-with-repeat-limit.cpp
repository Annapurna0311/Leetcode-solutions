class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(char i:s){
            freq[i - 'a']++;
        }
        priority_queue<pair<int,int>>  pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push({'a'+i , freq[i]});
        }
        string res;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int mini = min(repeatLimit , i.second);
            res.append(mini , i.first);
            i.second -= mini;
            if(i.second > 0){
                if(pq.empty()) break;
                auto x = pq.top();
                pq.pop();
                res += x.first;
                x.second--;
                if(x.second > 0) pq.push({x.first , x.second});
                pq.push({i.first , i.second});
            }
        }
        return res;
    }
};