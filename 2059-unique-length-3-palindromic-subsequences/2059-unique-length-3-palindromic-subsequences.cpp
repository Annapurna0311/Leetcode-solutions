class Solution{
   public:
     int countPalindromicSubsequence(string s){
         int res=0;
         unordered_set<char> uniq;
         for(char ch: s){
            uniq.insert(ch);
         }
         for(char ch: uniq){
             int start = s.find(ch);
             int end = s.rfind(ch);
             if(start < end){
                 unordered_set<char> charSet;
                 for(int i= start+1;i<end;i++){
                     charSet.insert(s[i]);
                 }
                 res+= charSet.size();
             }
         }
         return res;
     }
};