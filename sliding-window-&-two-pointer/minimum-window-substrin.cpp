class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hashmap(256,0);
        int n=s.length();
        int m=t.length();
        for(int i=0; i<m;i++){
            hashmap[t[i]]++;
        }
        int l=0,r=0;
        int cnt=0;
        int stIndex=-1;
        int minLen=INT_MAX;
        while(r<n){
            if(hashmap[s[r]]>0) cnt++;
            hashmap[s[r]]--;
            while(cnt==m){
                if(minLen>r-l+1){
                    minLen=r-l+1;
                    stIndex=l;
                }
                hashmap[s[l]]++;
                if(hashmap[s[l]]>0) cnt--;
                l++;



            }
            r++;
        }
        return (stIndex==-1) ? "" : s.substr(stIndex,minLen);
    }
};
