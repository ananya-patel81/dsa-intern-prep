class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        int maxlen=0;
        vector<int> hashmap(256,-1);

        while(r<n){
            if(hashmap[s[r]]!=-1){
                if(hashmap[s[r]]>=l){
                    l=hashmap[s[r]]+1;
                }
                
                
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hashmap[s[r]]=r;
            r++;

        }
        return maxlen;
        
    }
};
