class Solution {
  public:
    string minWindow(string& s, string& t) {
        // Code here
        int n=s.length();
        int m=t.length();
        int i=0;
        int j=0;
        int stInd=-1;
        int minLen=INT_MAX;
        while(i<n){
            if(s[i]==t[j]) j++;
            if(j==m){
                int end=i;
                j--;
                while(j>=0){
                    if(s[i]==t[j]){
                        
                        j--;
                    }
                    if(j>=0) i--;
                }
                int currlen=end-i+1;
                if(minLen>currlen){
                    minLen=currlen;
                    stInd=i;
                }
                j=0; 
                
            }
            i++;
        }
        return (stInd==-1) ? "" : s.substr(stInd,minLen);
        
        
        
    }
};
